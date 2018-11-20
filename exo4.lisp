(defun cl(l)
	(if l)
		(if (listp (car l))
			t
			(cl (cdr l))
		)
		nil
	)
)




