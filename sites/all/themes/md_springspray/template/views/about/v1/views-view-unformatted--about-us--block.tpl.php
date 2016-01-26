<?php
	$count = count($rows);
	$col = 0;
	switch($count) :
		case 1 :
			$col = 12;
			break;
		case 2 :
			$col = 6;
			break;
		case 3 :
			$col = 4;
			break;
		default :
			$col = 3;
			break;	
	endswitch;
?>
<article class="text-center">		
	<div class="row">
		<?php foreach ($rows as $id => $row): ?>
            <div class="col-md-<?php print $col; ?>">
                <?php print $row; ?>
            </div>
        <?php endforeach; ?>
	</div>
</article>	