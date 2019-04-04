/**
 * File name: RkCairoGraphicsBackend.cpp
 * Project: Redkite (A small GUI toolkit)
 *
 * Copyright (C) 2019 Iurie Nistor (http://quamplex.com/redkite)
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

#include "RkCairoGraphicsBackend.h"
#include "RkCanvas.h"
#include "RkCanvasInfo.h"
#include "RkLog.h"

#include <math.h>

RkCairoGraphicsBackend::RkCairoGraphicsBackend(RkCanvas *canvas)
        : cairoContext{cairo_create(canvas->getCanvasInfo()->cairo_surface)}
        , fontSize{12}
{
        cairo_set_font_size(cairoContext, getFontSize());
        cairo_set_line_width (cairoContext, 1);
}

cairo_t* RkCairoGraphicsBackend::context()
{
        return cairoContext;
}

RkCairoGraphicsBackend::~RkCairoGraphicsBackend()
{
        cairo_destroy(context());
}

void RkCairoGraphicsBackend::drawText(const std::string &text, int x, int y)
{
        cairo_move_to(context(), x, y);
        cairo_show_text(context(), text.c_str());
}

void RkCairoGraphicsBackend::drawImage(const std::string &file, int x, int y)
{
        auto image = cairo_image_surface_create_from_png(file.c_str());
        cairo_set_source_surface(context(), image, x, y);
        cairo_paint(context());
        cairo_surface_destroy(image);
}

void RkCairoGraphicsBackend::drawImage(const RkImage &image, int x, int y)
{
        auto stride = cairo_format_stride_for_width(CAIRO_FORMAT_ARGB32, image.width());
        auto image_data = image.dataCopy();
        auto img = cairo_image_surface_create_for_data(image_data.data(),
                                                       CAIRO_FORMAT_ARGB32,
                                                       image.width(),
                                                       image.height(),
                                                       stride);
        cairo_set_source_surface(context(), img, x, y);
        cairo_paint(context());
        cairo_surface_destroy(img);
}

void RkCairoGraphicsBackend::drawEllipse(const RkPoint& p, int width, int height)
{
        if (width == height) {
                cairo_arc(context(), p.x(), p.y(), width / 2, 0, 2 * M_PI);
                cairo_stroke(context());
        } else {
                // TODO: implemented ellipse.
                RK_LOG_ERROR("ellipse not implemented yet");
        }
}

void RkCairoGraphicsBackend::drawLine(const RkPoint &p1, const RkPoint &p2)
{
        cairo_move_to(context(), p1.x(), p1.y());
        cairo_line_to(context(), p2.x(), p2.y());
        cairo_stroke(context());
}

void RkCairoGraphicsBackend::setPen(const RkPen &pen)
{
        cairo_set_line_width(context(), pen.width());
        cairo_set_source_rgba(context(),
                              static_cast<double>(pen.color().red()) / 255,
                              static_cast<double>(pen.color().green()) / 255,
                              static_cast<double>(pen.color().blue()) / 255,
                              static_cast<double>(pen.color().alpha()) / 255);
        double dashLine[] = {12, 8};
        double dotLine[] = {1, 2};
        switch (pen.style())
        {
        case RkPen::PenStyle::DashLine:
                cairo_set_dash(context(), dashLine, 2, 0);
                break;
        case RkPen::PenStyle::DotLine:
                cairo_set_dash(context(), dotLine, 2, 0);
                break;
        case RkPen::PenStyle::NoLine:
        case RkPen::PenStyle::SolidLine:
        default:
                cairo_set_dash(context(), nullptr, 0, 0);
                break;
        }
}

int RkCairoGraphicsBackend::getFontSize() const
{
        return fontSize;
}

void RkCairoGraphicsBackend::setFontSize(int size)
{
        fontSize = size;
}

