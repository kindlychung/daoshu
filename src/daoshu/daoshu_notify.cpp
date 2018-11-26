#include <libnotify/notify.h>
#include <iostream>

bool notify() {
    notify_init("Daoshu");
    NotifyNotification* n = notify_notification_new(
        "Time is up",
        "What did you set the timer for? It's time to get it done!", "daoshu");
    notify_set_app_name("Daoshu");
    notify_notification_set_hint(n, "desktop-entry",
                                 g_variant_new_string("daoshu"));
    notify_notification_set_timeout(n, 0);  // 1 hour
    if (!notify_notification_show(n, 0)) {
        std::cerr << "failed to show notification" << std::endl;
        return 1;
    }
    return 0;
}