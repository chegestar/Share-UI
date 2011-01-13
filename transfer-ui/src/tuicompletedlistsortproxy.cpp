
/*
 * This file is part of Handset UX Transfer user interface
 *
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies). All rights reserved.
 * Contact: Jukka Tiihonen <jukka.tiihonen@nokia.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to 
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense,     
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  
 * IN THE SOFTWARE. 
 */








 //local headers
#include "tuicompletedlistsortproxy.h"
#include "tuistructures.h"
#include "tuidatamodel.h"
#include "tuicompletedlistmodel.h"

//Qt headers
#include <QDebug>

TUICompletedListSortProxy::TUICompletedListSortProxy(QObject *parent) :
   QSortFilterProxyModel(parent) {

}


TUICompletedListSortProxy::~TUICompletedListSortProxy() {

}

bool TUICompletedListSortProxy::lessThan(const QModelIndex &left, const
   QModelIndex &right) const {

    bool retVal = false;

    QVariant leftData = left.data();
    TUIData *leftTUIData = leftData.value<TUIData*>();

    QVariant rightData = right.data();
    TUIData *rightTUIData = rightData.value<TUIData*>();

    if((leftTUIData != 0) && (rightTUIData != 0 )) {
        if(leftTUIData->completedTime > rightTUIData->completedTime) {
            retVal = true;
        }
    }
    return retVal;
}