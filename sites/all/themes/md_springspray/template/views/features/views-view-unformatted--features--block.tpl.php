<?php $count = 0; ?>
<div class="row sp_block_wrap">
	<?php foreach ($rows as $id => $row): ?>
        <div class="col <?php (($count%2)==0) ? print 'firstcol' : print '';  ?> col50 col_br_100">	
			<?php print $row; ?>
        </div>
        <?php $count++; ?>
    <?php endforeach; ?>
</div>