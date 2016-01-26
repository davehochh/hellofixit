<div class="col-md-3 col-sm-6">
    <div class="pentagon clearfix">
        <a href="#team<?php print $fields['nid']->content; ?>" class="teampopup">
            <img alt="" src="<?php print $fields['field_team_image']->content; ?>" />
        </a>
        <div class="ab-heading">
            <h4><?php print $fields['title']->content; ?><br><small><?php print $fields['field_team_position']->content; ?></small></h4>		
            
        </div>
        <div class="profile-social-wrapper">
            <?php if(isset($row->field_field_team_socials)) : ?>
				<?php for($i=0; $i < count($row->field_field_team_socials); $i++) : ?>
                    <?php
                        $id = $row->field_field_team_socials[$i]['raw']['value'];
                        $icon = $row->field_field_team_socials[$i]['rendered']['entity']['field_collection_item'][$id]['field_team_socials_icon']['#items'][0]['value'];
                        $link = $row->field_field_team_socials[$i]['rendered']['entity']['field_collection_item'][$id]['field_team_socials_link']['#items'][0]['value'];
                    ?>
                    <div class="link" data-href="<?php print $link; ?>">
                        <div class="cube twitter">
                            <div class="frontend">
                                <i class="fa <?php print $icon; ?>"></i>
                            </div>
                            <div class="back">
                                <i class="fa <?php print $icon; ?>"></i>
                            </div>
                        </div>
                    </div>
                <?php endfor; ?>
            <?php endif; ?>			
        </div>
    </div>
    <div id="team<?php print $fields['nid']->content; ?>" class="team_detail clearfix">
        <div class="detail_image">
            <img alt="" src="<?php print $fields['field_team_image']->content; ?>" />
        </div>
        <div class="detail_content">
        <h4><?php print $fields['title']->content; ?><br><small><?php print $fields['field_team_position']->content; ?></small></h4>										
        <p><?php print $fields['field_team_description']->content; ?></p>
        <h4><small><?php print t('Technical skills'); ?></small></h4> 
        <p><?php print $fields['field_team_skills']->content; ?></p>
        </div>
    </div>
</div>