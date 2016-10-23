#include <glib.h>
#include <stdlib.h>

#include "gtkwheelcontrol_priv.h"

/*!
 * Перечисление свойств виджета.
 */
enum {
    PROP_0 = 0, //!< Код 0 использовать нельзя.
    PROP_ROUND_OFFSET,
    PROP_ROUND_LENGTH
};

//! Регистрация типа данных GtkWheelControl с объявлением служебных функций.
G_DEFINE_TYPE_WITH_PRIVATE(GtkWheelControl, gtk_wheel_control, GTK_TYPE_WIDGET);

static void gtk_wheel_control_finalize(GObject *object)
{
    GtkWheelControl *wheel_control = GTK_WHEEL_CONTROL(object);
    GtkWheelControlPrivate *priv =
            gtk_wheel_control_get_instance_private(wheel_control);

    G_OBJECT_CLASS(gtk_wheel_control_parent_class)->finalize(object);
}

void gtk_wheel_control_set_length(GtkWheelControl *wheel_control,
                                  gdouble length)
{
    GtkWheelControlPrivate *priv =
            gtk_wheel_control_get_instance_private(wheel_control);

    priv->round_length = length;
}

void gtk_wheel_control_set_offset(GtkWheelControl *wheel_control,
                                  gdouble offset)
{
    GtkWheelControlPrivate *priv =
            gtk_wheel_control_get_instance_private(wheel_control);

    priv->round_offset = offset;
}

static void gtk_wheel_control_set_property(GObject *object,
                                           guint prop_id,
                                           const GValue *value,
                                           GParamSpec *pspec)
{
    GtkWheelControl *wheel_control = GTK_WHEEL_CONTROL(object);
    GtkWheelControlPrivate *priv =
            gtk_wheel_control_get_instance_private(wheel_control);

    switch (prop_id) {
    case PROP_ROUND_LENGTH:
        gtk_wheel_control_set_length(wheel_control, g_value_get_double(value));
        break;
    case PROP_ROUND_OFFSET:
        gtk_wheel_control_set_offset(wheel_control, g_value_get_double(value));
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
        break;
    }
}

//! Получение значения свойства виджета по его идентификатору.
static void gtk_wheel_control_get_property(GObject *object,
                                           guint prop_id,
                                           GValue *value,
                                           GParamSpec *pspec)
{
    GtkWheelControl *wheel_control = GTK_WHEEL_CONTROL(object);
    GtkWheelControlPrivate *priv =
            gtk_wheel_control_get_instance_private(wheel_control);

    switch (prop_id) {
    case PROP_ROUND_OFFSET:
        g_value_set_double(value, priv->round_length);
        break;
    case PROP_ROUND_LENGTH:
        g_value_set_double(value, priv->round_offset);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
        break;
    }
}

static gboolean gtk_wheel_control_draw(GtkWidget *widget, cairo_t *cr)
{
    gtk_css_gadget_draw(GTK_LABEL(widget)->priv->gadget, cr);

    return FALSE;
}

//! Инициализация класса виджета.
static void gtk_wheel_control_class_init(GtkWheelControlClass *klass)
{
    GObjectClass *gobject_class = G_OBJECT_CLASS(klass);
    GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(klass);

    gobject_class->get_property = gtk_wheel_control_get_property;
    gobject_class->set_property = gtk_wheel_control_set_property;

    gobject_class->finalize = gtk_wheel_control_finalize;

    widget_class->draw = gtk_wheel_control_draw;

    g_object_class_install_property(gobject_class,
                                    PROP_ROUND_LENGTH,
                                    g_param_spec_double("length",
                                                        ("Round length"),
                                                        ("One round length"),
                                                        -G_MAXDOUBLE,
                                                        G_MAXDOUBLE,
                                                        0,
                                                        G_PARAM_READWRITE));
    g_object_class_install_property(
            gobject_class,
            PROP_ROUND_OFFSET,
            g_param_spec_double("offset",
                                ("Round offset"),
                                ("Offset relative to upper point"),
                                -G_MAXDOUBLE,
                                G_MAXDOUBLE,
                                0,
                                G_PARAM_READWRITE));
}

//! Инициализация виджета (при создании).
static void gtk_wheel_control_init(GtkWheelControl *wheel_control)
{
    GtkWidget *widget = GTK_WIDGET(wheel_control);

    GtkWheelControlPrivate *priv =
            gtk_wheel_control_get_instance_private(wheel_control);

    wheel_control->priv = priv;
    priv->self = GTK_WIDGET(wheel_control);

    priv->round_length = 1.0;

    priv->round_offset = 0;
}

//! Функция создания виджета.
GtkWidget *gtk_wheel_control_new(void)
{
    // вызов конструктора класса с передачей в конструктор параметров.
    GtkWidget *wheel_control = GTK_WIDGET(
            g_object_new(GTK_TYPE_WHEEL_CONTROL, NULL));

    return wheel_control;
}
