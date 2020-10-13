#pragma once

#include "ItemVisitor.h"

/**
* A visitor that will check if there are too 
* many predators than prey.
* 
* Too many in this case is if there are less
* than twice as many prey as predators.
*/
class CPredatorPreyBalance
	: public CItemVisitor
{
public:
	virtual ~CPredatorPreyBalance() {};

	void VisitFishAngler(CFishAngler* item) override;

	void VisitFishBeta(CFishBeta* fish) override;

	void VisitFishMolly(CFishMolly* fish) override;

	void VisitFishNemo(CFishNemo* fish) override;

	bool TooManyPredators();

private:

	int mPrey=0;
	int mPredator=0;
};

