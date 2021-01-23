/**
 * File name: RkGraphicsView.cpp
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

#include "RkGraphicsView.h"

RkGraphicsView::RkGraphicsView(RkWidget *parent, RkGraphicsModel *model)
	: RkWidget(parent, std::make_unique<RkGraphicsView::RkGraphicsViewImpl>(this, parent, model))
	, impl_ptr{static_cast<RkGraphicsView::RkGraphicsViewImpl*>(o_ptr.get())}
{
}

void RkGraphicsView::mouseButtonPressEvent(RkMouseEvent *event)
{
	impl_ptr->model()->onMouseEvent(event);
}

void RkGraphicsView::mouseButtonReleaseEvent(RkMouseEvent *event)
{
}

void RkGraphicsView::mouseDoubleClickEvent(RkMouseEvent *event)
{
}

void RkGraphicsView::wheelEvent(RkWheelEvent *event)
{
}

void RkGraphicsView::mouseMoveEvent(RkMouseEvent *event)
{
}

void RkGraphicsView::paintEvent(RkPaintEvent *event)
{
	RkPainter painter(this);
	impl_ptr->model()->render(painter, rect());
}
