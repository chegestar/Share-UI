
/*
 * transfer-ui -- Handset UX Transfer user interface
 * Copyright (c) 2010-2011 Nokia Corporation and/or its subsidiary(-ies).
 * Contact: Jukka Tiihonen <jukka.tiihonen@nokia.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "persistenttransfer.h"
#include "transferui_interface.h"
#include "transferprivate.h"

using namespace TransferUI;

PersistentTransfer::PersistentTransfer (ComMeegoTransferuiInterface * interface,
    const QString & id, Client * parent) : Transfer (parent) {

    d_ptr->interface = interface;
    d_ptr->id = id;

}

PersistentTransfer::~PersistentTransfer() {

}
/*
bool PersistentTransfer::markFailed (const QString & message,
    const QString & description) {

    Q_UNUSED (message);
    Q_UNUSED (description);

    return false;
}
*/
