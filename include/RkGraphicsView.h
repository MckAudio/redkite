/**
 * File name: RkGraphicsView.h
 * Project: Redkite (A small GUI toolkit)
 *
 * Copyright (C) 2021 Iurie Nistor <http://iurieweb.wordpress.com>
 *
 * This file is part of Redkite.
 *
 * Redkite is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef RK_GRAPHICS_VIEW_H
#define RK_GRAPHICS_VIEW_H

class RkGraphicsView: public RkWidget {
 public:
	RkGraphicsView(RkWidget *parent, RkGraphicsModel *model);
	virtual ~RkGraphicsView();
	void setModel(RkGraphicsModel *model);
	RkGraphicsModel *model() const;
	
 protected:
	void mouseMoveEvent(RkMouseEvent *event) override;
	void mouseButtonPressEvent(RkMouseEvent *event) override;
        void mouseButtonReleaseEvent(RkMouseEvent *event) override;
        void mouseDoubleClickEvent(RkMouseEvent *event) override;
	void wheelEvent(RkWheelEvent *event) override;
	void paintEvent(RkPaintEvent *event) override;

 private:
    RK_DISABLE_COPY(RkGraphicsView);
    RK_DISABLE_MOVE(RkGraphicsView);
    RK_DELCATE_IMPL_PTR(RkGraphicsView);
};

#endif // RK_GRAPHICS_VIEW_H
