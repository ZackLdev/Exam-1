/**
* \file FishNemo.h
*
* \author Charles B. Owen
*
* Class the implements a Nemo fish
*/

#pragma once

#include <memory>

#include "Item.h"



class CItemVisitor;


/**
* Implements a Nemo fish
*/
class CFishNemo : public CItem
{
public:
	CFishNemo(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishNemo() = delete;

	/// Copy constructor (disabled)
	CFishNemo(const CFishNemo &) = delete;

	virtual void Draw(Gdiplus::Graphics *graphics) override;
	virtual bool HitTest(int x, int y) override;

	virtual void Accept(CItemVisitor* visitor);

private:
	/// The image of this fish
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};