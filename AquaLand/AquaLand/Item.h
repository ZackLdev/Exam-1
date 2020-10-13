/**
* \file Item.h
*
* \author Charles B. Owen
*
* Base class for any item in our aquarium.
*/

#pragma once

#include <memory>

class CAquarium;
class CItemVisitor;

/**
* Base class for any item in our aquarium.
*/
class CItem
{
public:
    /// Default constructor (disabled)
    CItem() = delete;

    /// Copy constructor (disabled)
    CItem(const CItem&) = delete;

    virtual ~CItem();

    double Distance(std::shared_ptr<CItem> other);

    /** The X location of the item
    * \returns X location in pixels */
    double GetX() const { return mX; }

    /** The Y location of the item
    * \returns Y location in pixels */
    double GetY() const { return mY; }

    /// Set the item location
    /// \param x X location
    /// \param y Y location
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    /// Move the item by directly changing x,y by delta amounts
    /// \param dx X amount to move
    /// \param dy Y amount to move
    void Move(double dx, double dy) { mX += dx; mY += dy; }

    /// Draw this item
    /// \param graphics Graphics device to draw on
    virtual void Draw(Gdiplus::Graphics* graphics) = 0;

    /** Test this item to see if it has been clicked on
     * \param x X location on the aquarium to test
     * \param y Y location on the aquarium to test
     * \return true if clicked on */
    virtual bool HitTest(int x, int y) = 0;

    /** Accept a visitor for the item
    * \param visitor The visitor for the item
    */
    virtual void Accept(CItemVisitor* visitor) {}


protected:
    CItem(CAquarium* aquarium);

    /// Get the pointer to the CAquarium object
    /// \return Pointer to CAquarium object
    CAquarium* GetAquarium() { return mAquarium; }

private:
    /// The aquarium this item is contained in
    CAquarium* mAquarium;

    // Item location in the aquarium
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item
};