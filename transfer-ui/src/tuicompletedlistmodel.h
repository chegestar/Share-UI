
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








#ifndef _TUI_COMPLETED_LIST_MODEL_H_
#define _TUI_COMPLETED_LIST_MODEL_H_

//Qt Headers
#include <QAbstractListModel>

//local headers
#include "tuistructures.h"
#include "tuiabstractmodel.h"

using namespace TransferUI;

/*!
    \class TUICompletedListModel
    \brief model for the completed list
    \author  Jukka Tiihonen <jukka.t.tiihonen@nokia.com>
*/
class TUICompletedListModel : public TUIAbstractModel
{
    Q_OBJECT
public:

    TUICompletedListModel(QObject *parent=0);

    virtual ~TUICompletedListModel();

    //! \reimp
    int rowCount(const QModelIndex &parent) const;

    bool setData(const QModelIndex &index, const QVariant &value,
        int role=Qt::EditRole);

    bool insertRows(int position, int rows,
        const QModelIndex &index=QModelIndex());

    bool removeRows(int position, int rows,
        const QModelIndex &index=QModelIndex());

    bool setItemData ( const QModelIndex & index,
        const QMap<int, QVariant> & roles );

    QMap<int, QVariant> itemData ( const QModelIndex & index ) const;

    QModelIndex index ( int row, int column,
        const QModelIndex& parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;

    QModelIndex parent(const QModelIndex &child) const;

    int columnCount(const QModelIndex &parent) const;

    //! \reimp_end

    void thumbnailReady(const QModelIndex& index, const QImage* image);

    void clearThumbnails();

    void clearMessages();
Q_SIGNALS:
    void requestThumbnail(const QModelIndex& index);

	void modelEmpty(bool value);
private:
    QList<TUIData*> completedList; //!< List of completed list
};
#endif