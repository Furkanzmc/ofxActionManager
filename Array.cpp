/****************************************************************************
Copyright (c) 2007      Scott Lembcke
Copyright (c) 2010-2012 cocos2d-x.org
CopyRight (c) 2013-2014 Chukong Technologies Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "Array.h"
#include "ofLog.h"

/** Allocates and initializes a new array with specified capacity */
Array *ArrayNew(std::size_t capacity)
{
    if (capacity == 0)
        capacity = 7;

    Array *arr = (Array *)malloc(sizeof(Array));
    arr->num = 0;
    arr->arr = (Action **)calloc(capacity, sizeof(Action *));
    arr->max = capacity;

    return arr;
}

/** Frees array after removing all remaining objects. Silently ignores nullptr arr. */
void ArrayFree(Array *&arr)
{
    if (arr == nullptr) {
        return;
    }
    ArrayRemoveAllObjects(arr);

    free(arr->arr);
    free(arr);

    arr = nullptr;
}

void ArrayDoubleCapacity(Array *arr)
{
    arr->max *= 2;
    Action **newArr = (Action **)realloc(arr->arr, arr->max * sizeof(Action *));
    // will fail when there's not enough memory
    if (newArr == 0) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": ccArrayDoubleCapacity failed. Not enough memory";
        return;
    }
    arr->arr = newArr;
}

void ArrayEnsureExtraCapacity(Array *arr, std::size_t extra)
{
    while (arr->max < arr->num + extra) {
        ArrayDoubleCapacity(arr);
    }
}

void ArrayShrink(Array *arr)
{
    std::size_t newSize = 0;

    //only resize when necessary
    if (arr->max > arr->num && !(arr->num == 0 && arr->max == 1)) {
        if (arr->num != 0) {
            newSize = arr->num;
            arr->max = arr->num;
        }
        else {
            //minimum capacity of 1, with 0 elements the array would be free'd by realloc
            newSize = 1;
            arr->max = 1;
        }

        arr->arr = (Action **)realloc(arr->arr, newSize * sizeof(Action *));
        if (arr->arr == nullptr) {
            ofLogError("ofxActionManager") << __FUNCTION__ << ": Could not reallocate the memory.";
            return;
        }
    }
}

/** Returns index of first occurrence of object, INVALID_INDEX if object not found. */
std::size_t ArrayGetIndexOfObject(Array *arr, Action *object)
{
    const auto arrNum = arr->num;
    Action **ptr = arr->arr;
    for (std::size_t i = 0; i < arrNum; ++i, ++ptr) {
        if (*ptr == object)
            return i;
    }

    return INVALID_INDEX;
}

/** Returns a Boolean value that indicates whether object is present in array. */
bool ArrayContainsObject(Array *arr, Action *object)
{
    return ArrayGetIndexOfObject(arr, object) != INVALID_INDEX;
}

/** Appends an object. Behavior undefined if array doesn't have enough capacity. */
void ArrayAppendObject(Array *arr, Action *object)
{
    if (object == nullptr) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": Invalid parameter!";
        return;
    }

    arr->arr[arr->num] = object;
    arr->num++;
}

/** Appends an object. Capacity of arr is increased if needed. */
void ArrayAppendObjectWithResize(Array *arr, Action *object)
{
    ArrayEnsureExtraCapacity(arr, 1);
    ArrayAppendObject(arr, object);
}

/** Appends objects from plusArr to arr. Behavior undefined if arr doesn't have
 enough capacity. */
void ArrayAppendArray(Array *arr, Array *plusArr)
{
    for (std::size_t i = 0; i < plusArr->num; i++) {
        ArrayAppendObject(arr, plusArr->arr[i]);
    }
}

/** Appends objects from plusArr to arr. Capacity of arr is increased if needed. */
void ArrayAppendArrayWithResize(Array *arr, Array *plusArr)
{
    ArrayEnsureExtraCapacity(arr, plusArr->num);
    ArrayAppendArray(arr, plusArr);
}

/** Inserts an object at index */
void ArrayInsertObjectAtIndex(Array *arr, Action *object, std::size_t index)
{
    if (index >= arr->num) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": Invalid index. Out of bounds";
        return;
    }
    if (object == nullptr) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": Invalid parameter!";
        return;
    }

    ArrayEnsureExtraCapacity(arr, 1);

    std::size_t remaining = arr->num - index;
    if (remaining > 0) {
        memmove((void *)&arr->arr[index + 1], (void *)&arr->arr[index], sizeof(Action *) * remaining);
    }

    arr->arr[index] = object;
    arr->num++;
}

/** Swaps two objects */
void ArraySwapObjectsAtIndexes(Array *arr, std::size_t index1, std::size_t index2)
{
    if ((index1 >= 0 && index1 < arr->num) == false) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": (1) Invalid index. Out of bounds";
        return;
    }
    if ((index2 >= 0 && index2 < arr->num) == false) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": (2) Invalid index. Out of bounds";
        return;
    }

    Action *object1 = arr->arr[index1];

    arr->arr[index1] = arr->arr[index2];
    arr->arr[index2] = object1;
}

/** Removes all objects from arr */
void ArrayRemoveAllObjects(Array *arr)
{
    while (arr->num > 0) {
        (arr->arr[--arr->num])->release();
    }
}

/** Removes object at specified index and pushes back all subsequent objects.
 Behavior undefined if index outside [0, num-1]. */
void ArrayRemoveObjectAtIndex(Array *arr, std::size_t index, bool releaseObj/* = true*/)
{
    if ((arr && arr->num > 0 && index >= 0 && index < arr->num) == false) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": Invalid index. Out of bounds";
        return;
    }

    if (releaseObj) {
        SAFE_RELEASE(arr->arr[index]);
    }

    arr->num--;

    std::size_t remaining = arr->num - index;
    if (remaining > 0) {
        memmove((void *)&arr->arr[index], (void *)&arr->arr[index + 1], remaining * sizeof(Action *));
    }
}

/** Removes object at specified index and fills the gap with the last object,
 thereby avoiding the need to push back subsequent objects.
 Behavior undefined if index outside [0, num-1]. */
void ArrayFastRemoveObjectAtIndex(Array *arr, std::size_t index)
{
    SAFE_RELEASE(arr->arr[index]);
    auto last = --arr->num;
    arr->arr[index] = arr->arr[last];
}

void ArrayFastRemoveObject(Array *arr, Action *object)
{
    auto index = ArrayGetIndexOfObject(arr, object);
    if (index != INVALID_INDEX) {
        ArrayFastRemoveObjectAtIndex(arr, index);
    }
}

/** Searches for the first occurrence of object and removes it. If object is not
 found the function has no effect. */
void ArrayRemoveObject(Array *arr, Action *object, bool releaseObj/* = true*/)
{
    auto index = ArrayGetIndexOfObject(arr, object);
    if (index != INVALID_INDEX) {
        ArrayRemoveObjectAtIndex(arr, index, releaseObj);
    }
}

/** Removes from arr all objects in minusArr. For each object in minusArr, the
 first matching instance in arr will be removed. */
void ArrayRemoveArray(Array *arr, Array *minusArr)
{
    for (std::size_t i = 0; i < minusArr->num; i++) {
        ArrayRemoveObject(arr, minusArr->arr[i]);
    }
}

/** Removes from arr all objects in minusArr. For each object in minusArr, all
 matching instances in arr will be removed. */
void ArrayFullRemoveArray(Array *arr, Array *minusArr)
{
    std::size_t back = 0;

    for (std::size_t i = 0; i < arr->num; i++) {
        if (ArrayContainsObject(minusArr, arr->arr[i])) {
            SAFE_RELEASE(arr->arr[i]);
            back++;
        }
        else {
            arr->arr[i - back] = arr->arr[i];
        }
    }

    arr->num -= back;
}

//
// // ccCArray for Values (c structures)

/** Allocates and initializes a new C array with specified capacity */
ccCArray *CArrayNew(std::size_t capacity)
{
    if (capacity == 0) {
        capacity = 7;
    }

    ccCArray *arr = (ccCArray *)malloc(sizeof(ccCArray));
    arr->num = 0;
    arr->arr = (void **)malloc(capacity * sizeof(void *));
    arr->max = capacity;

    return arr;
}

/** Frees C array after removing all remaining values. Silently ignores nullptr arr. */
void CArrayFree(ccCArray *arr)
{
    if (arr == nullptr) {
        return;
    }
    CArrayRemoveAllValues(arr);

    free(arr->arr);
    free(arr);
}

/** Doubles C array capacity */
void CArrayDoubleCapacity(ccCArray *arr)
{
    ArrayDoubleCapacity((Array *)arr);
}

/** Increases array capacity such that max >= num + extra. */
void CArrayEnsureExtraCapacity(ccCArray *arr, std::size_t extra)
{
    ArrayEnsureExtraCapacity((Array *)arr, extra);
}

/** Returns index of first occurrence of value, INVALID_INDEX if value not found. */
std::size_t CArrayGetIndexOfValue(ccCArray *arr, void *value)
{
    for (std::size_t i = 0; i < arr->num; i++) {
        if (arr->arr[i] == value)
            return i;
    }
    return INVALID_INDEX;
}

/** Returns a Boolean value that indicates whether value is present in the C array. */
bool CArrayContainsValue(ccCArray *arr, void *value)
{
    return CArrayGetIndexOfValue(arr, value) != INVALID_INDEX;
}

/** Inserts a value at a certain position. Behavior undefined if array doesn't have enough capacity */
void CArrayInsertValueAtIndex(ccCArray *arr, void *value, std::size_t index)
{
    if ((index < arr->max) == false) {
        ofLogError("ofxActionManager") << __FUNCTION__ << ": Invalid index";
        return;
    }

    auto remaining = arr->num - index;
    // make sure it has enough capacity
    if (arr->num + 1 == arr->max) {
        CArrayDoubleCapacity(arr);
    }
    // last Value doesn't need to be moved
    if (remaining > 0) {
        // tex coordinates
        memmove((void *)&arr->arr[index + 1], (void *)&arr->arr[index], sizeof(void *) * remaining);
    }

    arr->num++;
    arr->arr[index] = value;
}

/** Appends an value. Behavior undefined if array doesn't have enough capacity. */
void CArrayAppendValue(ccCArray *arr, void *value)
{
    arr->arr[arr->num] = value;
    arr->num++;
    // double the capacity for the next append action
    // if the num >= max
    if (arr->num >= arr->max) {
        CArrayDoubleCapacity(arr);
    }
}

/** Appends an value. Capacity of arr is increased if needed. */
void CArrayAppendValueWithResize(ccCArray *arr, void *value)
{
    CArrayEnsureExtraCapacity(arr, 1);
    CArrayAppendValue(arr, value);
}


/** Appends values from plusArr to arr. Behavior undefined if arr doesn't have
 enough capacity. */
void CArrayAppendArray(ccCArray *arr, ccCArray *plusArr)
{
    for (std::size_t i = 0; i < plusArr->num; i++) {
        CArrayAppendValue(arr, plusArr->arr[i]);
    }
}

/** Appends values from plusArr to arr. Capacity of arr is increased if needed. */
void CArrayAppendArrayWithResize(ccCArray *arr, ccCArray *plusArr)
{
    CArrayEnsureExtraCapacity(arr, plusArr->num);
    CArrayAppendArray(arr, plusArr);
}

/** Removes all values from arr */
void CArrayRemoveAllValues(ccCArray *arr)
{
    arr->num = 0;
}

/** Removes value at specified index and pushes back all subsequent values.
 Behavior undefined if index outside [0, num-1].
 */
void CArrayRemoveValueAtIndex(ccCArray *arr, std::size_t index)
{
    for (std::size_t last = --arr->num; index < last; index++) {
        arr->arr[index] = arr->arr[index + 1];
    }
}

/** Removes value at specified index and fills the gap with the last value,
 thereby avoiding the need to push back subsequent values.
 Behavior undefined if index outside [0, num-1].
 */
void CArrayFastRemoveValueAtIndex(ccCArray *arr, std::size_t index)
{
    std::size_t last = --arr->num;
    arr->arr[index] = arr->arr[last];
}

/** Searches for the first occurrence of value and removes it. If value is not found the function has no effect.
 */
void CArrayRemoveValue(ccCArray *arr, void *value)
{
    auto index = CArrayGetIndexOfValue(arr, value);
    if (index != INVALID_INDEX) {
        CArrayRemoveValueAtIndex(arr, index);
    }
}

/** Removes from arr all values in minusArr. For each Value in minusArr, the first matching instance in arr will be removed.
 */
void CArrayRemoveArray(ccCArray *arr, ccCArray *minusArr)
{
    for (std::size_t i = 0; i < minusArr->num; i++) {
        CArrayRemoveValue(arr, minusArr->arr[i]);
    }
}

/** Removes from arr all values in minusArr. For each value in minusArr, all matching instances in arr will be removed.
 */
void CArrayFullRemoveArray(ccCArray *arr, ccCArray *minusArr)
{
    std::size_t back = 0;

    for (std::size_t i = 0; i < arr->num; i++) {
        if (CArrayContainsValue(minusArr, arr->arr[i])) {
            back++;
        }
        else {
            arr->arr[i - back] = arr->arr[i];
        }
    }

    arr->num -= back;
}
