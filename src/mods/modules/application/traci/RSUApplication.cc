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

#include "../../../../mods/modules/application/traci/RSUApplication.h"

using namespace veins;

Define_Module(veins::RSUApplication);

void RSUApplication::initialize(int stage)
{
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
        // Initializing members and pointers of your application goes here
        //EV << "Initializing " << par("appName").stringValue() << std::endl;
        currentServiceChannel = Channel::sch1;
    }
    else if (stage == 1) {
        // Initializing members that require initialized other modules goes here
    }
}

void RSUApplication::finish()
{
    DemoBaseApplLayer::finish();
    // statistics recording goes here
}

void RSUApplication::onBSM(DemoSafetyMessage* bsm)
{
    // Your application has received a beacon message from another car or RSU
    // code for handling the message goes here
}

void RSUApplication::onWSA(DemoServiceAdvertisment* wsa)
{
    if(TaxiPOIMessage* msg = dynamic_cast<TaxiPOIMessage*>(wsa)){
        int msgID = msg->getMsgID();
        std::vector<int>::iterator it = find(receivedMsgs->begin(), receivedMsgs->end(), msgID);
        if(it == receivedMsgs->end()){
            receivedMsgs->push_back(msgID);
            std::cout << "received new message" << endl;
        }
    }
}

void RSUApplication::handlePositionUpdate(cObject* obj)
{
    ChannelMobilityPtrType const mobility = check_and_cast<ChannelMobilityPtrType>(obj);
    curPosition = mobility->getPositionAt(simTime());
}

void RSUApplication::handleSelfMsg(cMessage* msg)
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
        DemoServiceAdvertisment* wsa = new DemoServiceAdvertisment();
        populateWSM(wsa);
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
