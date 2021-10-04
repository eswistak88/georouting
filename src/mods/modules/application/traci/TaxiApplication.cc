//
// Copyright (C) 2016 David Eckhoff <david.eckhoff@fau.de>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "../../../../mods/modules/application/traci/TaxiApplication.h"

using namespace veins;

Define_Module(veins::TaxiApplication);

void TaxiApplication::initialize(int stage)
{
    NewBaseApplLayer::initialize(stage);
    if (stage == 0) {
        // Initializing members and pointers of your application goes here
        //EV << "Initializing " << par("appName").stringValue() << std::endl;
        currentServiceChannel = Channel::sch1;
    }
    else if (stage == 1) {
        // Initializing members that require initialized other modules goes here
        TaxiPOIMessage* msg = new TaxiPOIMessage();
        msg->setMsgID(msgID);
        msgID++;
        msg->setTargetPOI(0);
        msg->setSenderPos(curPosition);
        msg->setSender(myId);
        currentWSAID = msgID;
        startService(currentServiceChannel, 1, "");
        TraCICoord topleft = TraCICoord(0,0);
        TraCICoord bottomright = TraCICoord(60256.04,31795.18);
        TraCICoordinateTransformation transform = VEINS_API::TraCICoordinateTransformation(topleft, bottomright, 0.0);
        for(int i = 0; i<16; i++){
            POIcoords[i] = transform.traci2omnet(TraciPOIcoords[i]);
        }


    }
}

void TaxiApplication::finish()
{
    NewBaseApplLayer::finish();
    // statistics recording goes here
}

void TaxiApplication::onBSM(DemoSafetyMessage* bsm)
{
    if(RSUBeacon* msg = dynamic_cast<RSUBeacon*>(bsm)){
        visitedPOI[msg->getPOIID()] = true;
    }else if(TaxiBeacon* msg = dynamic_cast<TaxiBeacon*>(bsm)){
        //not currently doing anything for that
    }

}


void TaxiApplication::onWSA(DemoServiceAdvertisment* wsa)
{
    // Your application has received a service advertisement from another car or RSU
    // code for handling the message goes here, see TraciDemo11p.cc for examples
    if(TaxiPOIMessage* msg = dynamic_cast<TaxiPOIMessage*>(wsa)){
        //if you have visited the POI
        if(visitedPOI[msg->getTargetPOI()]){
            //you are closer to the POI
            Coord senderPos = msg->getSenderPos();
            int target = msg->getTargetPOI();
            Coord targetPos = POIcoords[target];
            if(senderPos.distance(targetPos)
                    < curPosition.distance(targetPos)){
                //retransmit the message
                currentWSAID = msg->getMsgID();
            }
        }
    }
}

void TaxiApplication::handlePositionUpdate(cObject* obj)
{
    NewBaseApplLayer::handlePositionUpdate(obj);
}

void TaxiApplication::handleSelfMsg(cMessage* msg)
{
    switch (msg->getKind()) {
    case SEND_BEACON_EVT: {
        DemoSafetyMessage* bsm = new DemoSafetyMessage();
        populateWSM(bsm);
        sendDown(bsm);
        scheduleAt(simTime() + beaconInterval, sendBeaconEvt);
        break;
    }
    case SEND_WSA_EVT: {
        TaxiPOIMessage* wsa = new TaxiPOIMessage();
        wsa->setTargetPOI(0);
        wsa->setSender(myId);
        wsa->setSenderPos(curPosition);
        wsa->setMsgID(currentWSAID);
        sendDown(wsa);
        scheduleAt(simTime() + wsaInterval, sendWSAEvt);
        break;
    }
    default: {
        if (msg) EV_WARN << "APP: Error: Got Self Message of unknown kind! Name: " << msg->getName() << endl;
        break;
    }
    }
}


