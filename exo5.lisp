a)

(defun point(entier)
	(if (> entier 0)
		(
			'.
			(point (- entier 1))
		) 
	)
)

(defun point(entier)(if (> entier 0)('.(point (- entier 1)))))
