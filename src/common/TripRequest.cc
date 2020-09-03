/*
########################################################
##           __  __       _____   _____ _             ##
##     /\   |  \/  |     |  __ \ / ____(_)            ##
##    /  \  | \  / | ___ | |  | | (___  _ _ __ ___    ##
##   / /\ \ | |\/| |/ _ \| |  | |\___ \| | '_ ` _ \   ##
##  / ____ \| |  | | (_) | |__| |____) | | | | | | |  ##
## /_/    \_\_|  |_|\___/|_____/|_____/|_|_| |_| |_|  ##
##                                                    ##
## Author:                                            ##
##    Andrea Di Maria                                 ##
##    <andrea.dimaria90@gmail.com>                    ##
########################################################
*/

#include <TripRequest.h>


int TripRequest::nextID = 0;

TripRequest::TripRequest() {
    id = ++nextID;
    pickup = nullptr;
    dropoff = nullptr;
    distanceToPickup = -1;
    vehicleID = -1;

    isSpecial = 0;
}

TripRequest::TripRequest(const TripRequest& other)
{
    copy(other);
}

void TripRequest::copy(const TripRequest& other)
{
    this->id = other.id;
    this->pickup = other.pickup ? new StopPoint(*other.pickup) : nullptr;
    this->dropoff = other.dropoff ? new StopPoint(*other.dropoff) : nullptr;
    this->distanceToPickup = other.distanceToPickup;
    this->vehicleID = other.vehicleID;
}


TripRequest::~TripRequest() {
    delete this->pickup;
    delete this->dropoff;
}

int TripRequest::getID() const
{
    return id;
}

StopPoint* TripRequest::getPickupSP() const
{
    return pickup;
}

void TripRequest::setPickupSP(StopPoint *pickupSP)
{
    this->pickup = pickupSP;
}

StopPoint* TripRequest::getDropoffSP() const
{
    return dropoff;
}

void TripRequest::setDropoffSP(StopPoint *dropoffSP)
{
    this->dropoff = dropoffSP;
}

int TripRequest::getVehicleID() const
{
    return vehicleID;
}

void TripRequest::setVehicleID(int vehicleID)
{
    this->vehicleID = vehicleID;
}


int TripRequest::getDistanceToPickup() const
{
    return distanceToPickup;
}

int TripRequest::getIsSpecial() const {
    return isSpecial;
}

void TripRequest::setIsSpecial(int isSpecial) {
    this->isSpecial = isSpecial;
}

void TripRequest::setDistanceToPickup(int distanceToPickup)
{
    this->distanceToPickup = distanceToPickup;
}
