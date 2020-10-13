#include "pch.h"
#include "PredatorPreyBalance.h"

#include "FishAngler.h"
#include "FishBeta.h"
#include "FishMolly.h"
#include "FishNemo.h"


/*
*/
void CPredatorPreyBalance::VisitFishAngler(CFishAngler* item)
{
	mPredator += 1;
}


void CPredatorPreyBalance::VisitFishBeta(CFishBeta* item)
{
	mPrey += 1;
}



void CPredatorPreyBalance::VisitFishMolly(CFishMolly* item)
{
	mPrey += 1;
}



void CPredatorPreyBalance::VisitFishNemo(CFishNemo* item)
{
	mPrey += 1;
}



bool CPredatorPreyBalance::TooManyPredators()
{
	if ((mPredator*2) > mPrey) {
		return true;
	}
	else {
		return false;
	}
}