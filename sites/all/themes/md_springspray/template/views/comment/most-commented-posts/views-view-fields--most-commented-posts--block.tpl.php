<a href="<?php print $fields['path']->content; ?>"><?php print $fields['title']->content; ?></a>
<span><?php print t('By @name on @date', array('@name' => $fields['name']->content, '@date' => $fields['created']->content)) ?></span>			