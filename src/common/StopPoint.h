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

#ifndef STOPPOINT_H_
#define STOPPOINT_H_

#include <omnetpp.h>

class StopPoint : public cObject{
    private:
    void copy(const StopPoint& other);

    protected:
        int requestID;
        int location;
        int x_coord;
        int y_coord;
        int numberOfPassengers;
        int actualNumberOfPassengers;
        bool isPickup;
        double time;
        double actualTime;
        double maxDelay;
        
        bool redCode; //is stop point of a red code emergency request
        bool needSkilledHospital;
        
    public:
        StopPoint();
        StopPoint(int requestID, int location, bool isPickup, double time, double maxDelay);
        StopPoint(const StopPoint& other);
        virtual ~StopPoint();

        virtual void setRequestID(int requestID);
        virtual int getRequestID() const;

        virtual void setNumberOfPassengers(int passengers);
        virtual int getNumberOfPassengers() const;

        virtual void setActualNumberOfPassengers(int passengers);
        virtual int getActualNumberOfPassengers() const;

        virtual void setLocation(int location);
        virtual int getLocation() const;

        virtual void setIsPickup(bool isPickup);
        virtual bool getIsPickup() const;

        virtual void setTime(double time);
        virtual double getTime() const;

        virtual void setActualTime(double actualTime);
        virtual double getActualTime() const;

        virtual void setMaxDelay(double maxDelay);
        virtual double getMaxDelay() const;

        virtual void setXcoord(int x_coord);
        virtual int getXcoord() const;

        virtual void setYcoord(int y_coord);
        virtual int getYcoord() const;
        virtual bool isRedCode() const;
        virtual void setRedCode(bool redCode);

        virtual double remainingTime();
	bool isNeedSkilledHospital() const;
	void setNeedSkilledHospital(bool needSkilledHospital);
};

#endif /* STOPPOINT_H_ */
