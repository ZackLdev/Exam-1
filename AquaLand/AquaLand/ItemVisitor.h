/**
 * \file TileVisitor.h
 *
 * \author CSE335 Course Staff
 *
 * A class that creates visitors for items.
 * Do not change this class!
 */

#pragma once

class CFishAngler;
class CFishBeta;
class CFishMolly;
class CFishNemo;

class CItemVisitor
{
public:
	virtual ~CItemVisitor() {}

	virtual void VisitFishAngler(CFishAngler* item) {}
	
	virtual void VisitFishBeta(CFishBeta* fish) {}

	virtual void VisitFishMolly(CFishMolly* fish) {}

	virtual void VisitFishNemo(CFishNemo* fish) {}
};


