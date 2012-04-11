<?php

/**
 * @file
 * Displays a user alert.
 *
 * Available variables:
 * - $alert_label: The label of the alert, as set in the User Alerts settings.
 * - $body: The user alert message.
 *
 * @ingroup themeable
 */

?>

<div id="user-alert-<?php print $nid; ?>" class="user-alert">
   <div class="user-alert-close"><a href="javascript:;" rel="<?php print $nid; ?>">x</a></div>
   <div class="user-alert-message"><?php if ($alert_label) : ?><span class="user-label"><?php print $alert_label; ?>:</span><?php endif; ?> <?php print $body; ?></div>
</div>
