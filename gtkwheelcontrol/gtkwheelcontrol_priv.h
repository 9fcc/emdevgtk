#ifndef GTK_WHEEL_CONTROL_PRIV_H_
#define GTK_WHEEL_CONTROL_PRIV_H_

#include <gtk/gtk.h>

#include "gtkwheelcontrol.h"
#include "gtkcsscustomgadget.h"

G_BEGIN_DECLS

//! Внутренние данные виджета.
struct _GtkWheelControlPrivate {
    GtkWidget *self;

    GtkCssGadget *gadget;

    gdouble round_length;
    gdouble round_offset;
};

G_END_DECLS

#endif /* GTK_WHEEL_CONTROL_PRIV_H_ */
