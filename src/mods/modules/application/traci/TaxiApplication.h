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

#pragma once

#include "mods/modules/application/ieee80211p/NewBaseApplLayer.h"
#include "veins/veins.h"
#include "veins/modules/mobility/traci/TraCICoord.h"

#include "veins/base/utils/Coord.h"

#include "mods/modules/messages/RSUBeacon_m.h"
#include "mods/modules/messages/TaxiBeacon_m.h"
#include "mods/modules/messages/TaxiPOIMessage_m.h"

using namespace omnetpp;

namespace veins {

/**
 * @brief
 * This is a stub for a typical Veins application layer.
 * Most common functions are overloaded.
 * See MyVeinsApp.cc for hints
 *
 * @author David Eckhoff
 *
 */

class VEINS_API TaxiApplication : public NewBaseApplLayer {
public:
    void initialize(int stage) override;
    void finish() override;

protected:
    void onBSM(DemoSafetyMessage* bsm) override;
    void onWSA(DemoServiceAdvertisment* wsa) override;

    void handleSelfMsg(cMessage* msg) override;
    void handlePositionUpdate(cObject* obj) override;

    bool initiateMessage = false;
    static int msgID;

private:
    int currentWSAID;
    bool visitedPOI[16] = {false};
    TraCICoord TraciPOIcoords[16] = {TraCICoord(23380.0,13837.0),
                            TraCICoord(23213.0,14027.0),
                            TraCICoord(35632.0,8092.0),
                            TraCICoord(26457.0,9882.0),
                            TraCICoord(24087.0,13184.0),
                            TraCICoord(23154.0,13800.0),
                            TraCICoord(22472.0,15811.0),
                            TraCICoord(22863.0,14654.0),
                            TraCICoord(24134.0,13275.0),
                            TraCICoord(22574.0,15806.0),
                            TraCICoord(24639.0,13075.0),
                            TraCICoord(21655.0,13272.0),
                            TraCICoord(23229.0,14085.0),
                            TraCICoord(31419.0,8650.0),
                            TraCICoord(25629.0,7761.0),
                            TraCICoord(23211.0,14077.0)};
    Coord POIcoords[16] = {Coord(0.0,0.0)};
};
int TaxiApplication::msgID = 0;
} // namespace veins

