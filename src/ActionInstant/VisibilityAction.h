#ifndef VISIBILITYACTION_H
#define VISIBILITYACTION_H
#include "ActionInstant.h"

/** @class Show
* @brief Show the node.
**/
class Show : public ActionInstant
{
public:
    /** Allocates and initializes the action.
     *
     * @return  An autoreleased Show object.
     */
    static Show *create();

    //
    // Overrides
    //
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;
    virtual ActionInstant *reverse() const override;
    virtual Show *clone() const override;

public:
    Show() {}
    virtual ~Show() {}

private:
    DISALLOW_COPY_AND_ASSIGN(Show);
};

/** @class Hide
* @brief Hide the node.
*/
class Hide : public ActionInstant
{
public:
    /** Allocates and initializes the action.
     *
     * @return An autoreleased Hide object.
     */
    static Hide *create();

    //
    // Overrides
    //
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;
    virtual ActionInstant *reverse() const override;
    virtual Hide *clone() const override;

public:
    Hide() {}
    virtual ~Hide() {}

private:
    DISALLOW_COPY_AND_ASSIGN(Hide);
};

/** @class ToggleVisibility
* @brief Toggles the visibility of a node.
*/
class ToggleVisibility : public ActionInstant
{
public:
    /** Allocates and initializes the action.
     *
     * @return An autoreleased ToggleVisibility object.
     */
    static ToggleVisibility *create();

    //
    // Overrides
    //
    /**
     * @param time In seconds.
     */
    virtual void update(float time) override;
    virtual ToggleVisibility *reverse() const override;
    virtual ToggleVisibility *clone() const override;

public:
    ToggleVisibility() {}
    virtual ~ToggleVisibility() {}

private:
    DISALLOW_COPY_AND_ASSIGN(ToggleVisibility);
};

#endif // VISIBILITYACTION_H
