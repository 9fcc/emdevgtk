#ifndef GTK_WHEEL_CONTROL_H_
#define GTK_WHEEL_CONTROL_H_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GTK_TYPE_WHEEL_CONTROL (gtk_wheel_control_get_type())

#define GTK_WHEEL_CONTROL(obj)                                                 \
    (G_TYPE_CHECK_INSTANCE_CAST((obj), GTK_TYPE_WHEEL_CONTROL, GtkWheelControl))

#define GTK_WHEEL_CONTROL_CLASS(klass)                                         \
    (G_TYPE_CHECK_CLASS_CAST(                                                  \
            (klass), GTK_TYPE_WHEEL_CONTROL, GtkWheelControlClass))

#define GTK_IS_WHEEL_CONTROL(obj)                                              \
    (G_TYPE_CHECK_INSTANCE_TYPE((obj), GTK_TYPE_WHEEL_CONTROL))

#define GTK_IS_WHEEL_CONTROLCLASS(klass)                                       \
    (G_TYPE_CHECK_CLASS_TYPE((klass), GTK_TYPE_WHEEL_CONTROL))

#define GTK_WHEEL_CONTROL_GET_CLASS(obj)                                       \
    (G_TYPE_INSTANCE_GET_CLASS(                                                \
            (obj), GTK_TYPE_WHEEL_CONTROL, GtkWheelControlClass))

typedef struct _GtkWheelControl GtkWheelControl;
typedef struct _GtkWheelControlPrivate GtkWheelControlPrivate;
typedef struct _GtkWheelControlClass GtkWheelControlClass;

struct _GtkWheelControl {
    GtkWidget box;

    GtkWheelControlPrivate *priv;
};

struct _GtkWheelControlClass {
    GtkWidgetClass parent_class;

    void (*reserved0)(void);
    void (*reserved1)(void);
    void (*reserved2)(void);
    void (*reserved3)(void);
    void (*reserved4)(void);
    void (*reserved5)(void);
    void (*reserved6)(void);
    void (*reserved7)(void);
};

void gtk_wheel_control_set_length(GtkWheelControl *wheel_control,
                                  gdouble length);
void gtk_wheel_control_set_offset(GtkWheelControl *wheel_control,
                                  gdouble offset);

G_END_DECLS

#endif /* GTK_WHEEL_CONTROL_H_ */
