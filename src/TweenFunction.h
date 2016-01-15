/****************************************************************************
Copyright (c) 2013-2015 Chukong Technologies Inc.

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

#ifndef __CCTWEENFUNCTION_H__
#define __CCTWEENFUNCTION_H__

namespace tweenfunc
{
enum TweenType {
    CUSTOM_EASING = -1,

    Linear,

    Sine_EaseIn,
    Sine_EaseOut,
    Sine_EaseInOut,


    Quad_EaseIn,
    Quad_EaseOut,
    Quad_EaseInOut,

    Cubic_EaseIn,
    Cubic_EaseOut,
    Cubic_EaseInOut,

    Quart_EaseIn,
    Quart_EaseOut,
    Quart_EaseInOut,

    Quint_EaseIn,
    Quint_EaseOut,
    Quint_EaseInOut,

    Expo_EaseIn,
    Expo_EaseOut,
    Expo_EaseInOut,

    Circ_EaseIn,
    Circ_EaseOut,
    Circ_EaseInOut,

    Elastic_EaseIn,
    Elastic_EaseOut,
    Elastic_EaseInOut,

    Back_EaseIn,
    Back_EaseOut,
    Back_EaseInOut,

    Bounce_EaseIn,
    Bounce_EaseOut,
    Bounce_EaseInOut,

    TWEEN_EASING_MAX = 10000
};


//tween functions for CCActionEase
/**
 * @param time in seconds.
 */
float easeIn(float time, float rate);

/**
 * @param time in seconds.
 */
float easeOut(float time, float rate);

/**
 * @param time in seconds.
 */
float easeInOut(float time, float rate);

/**
 * @param time in seconds.
 */
float bezieratFunction(float a, float b, float c, float d, float t);

/**
 * @param time in seconds.
 */
float quadraticIn(float time);

/**
 * @param time in seconds.
 */
float quadraticOut(float time);

/**
 * @param time in seconds.
 */
float quadraticInOut(float time);

/**
 * @param time in seconds.
 */
float quadraticInOut(float time);

/**
 * @param time in seconds.
 */
float tweenTo(float time, TweenType type, float *easingParam);

/**
 * @param time in seconds.
 */
float linear(float time);

/**
 * @param time in seconds.
 */
float sineEaseIn(float time);

/**
 * @param time in seconds.
 */
float sineEaseOut(float time);

/**
 * @param time in seconds.
 */
float sineEaseInOut(float time);

/**
 * @param time in seconds.
 */
float quadEaseIn(float time);

/**
 * @param time in seconds.
 */
float quadEaseOut(float time);

/**
 * @param time in seconds.
 */
float quadEaseInOut(float time);

/**
 * @param time in seconds.
 */
float cubicEaseIn(float time);

/**
 * @param time in seconds.
 */
float cubicEaseOut(float time);

/**
 * @param time in seconds.
 */
float cubicEaseInOut(float time);

/**
 * @param time in seconds.
 */
float quartEaseIn(float time);

/**
 * @param time in seconds.
 */
float quartEaseOut(float time);

/**
 * @param time in seconds.
 */
float quartEaseInOut(float time);

/**
 * @param time in seconds.
 */
float quintEaseIn(float time);

/**
 * @param time in seconds.
 */
float quintEaseOut(float time);

/**
 @param time in seconds.
 */
float quintEaseInOut(float time);

/**
 * @param time in seconds.
 */
float expoEaseIn(float time);

/**
 @param time in seconds.
 */
float expoEaseOut(float time);

/**
 * @param time in seconds.
 */
float expoEaseInOut(float time);

/**
 * @param time in seconds.
 */
float circEaseIn(float time);

/**
 * @param time in seconds.
 */
float circEaseOut(float time);

/**
 * @param time in seconds.
 */
float circEaseInOut(float time);

/**
 * @param time in seconds.
 * @param period in seconds.
 */
float elasticEaseIn(float time, float period);

/**
 * @param time in seconds.
 * @param period in seconds.
 */
float elasticEaseOut(float time, float period);

/**
 * @param time in seconds.
 * @param period in seconds.
 */
float elasticEaseInOut(float time, float period);

/**
 * @param time in seconds.
 */
float backEaseIn(float time);

/**
 * @param time in seconds.
 */
float backEaseOut(float time);

/**
 * @param time in seconds.
 */
float backEaseInOut(float time);

/**
 * @param time in seconds.
 */
float bounceEaseIn(float time);

/**
 * @param time in seconds.
 */
float bounceEaseOut(float time);

/**
 * @param time in seconds.
 */
float bounceEaseInOut(float time);

/**
 * @param time in seconds.
 */
float customEase(float time, float *easingParam);
}
#endif /*__CCTWEENFUNCTION_H__*/
