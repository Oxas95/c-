(defun func(x y)
	(if (> x y) 
		x 
		y
	)
)
(func 2 4)



bonus fonction qui compte

(defun compte(x)
	(if (eq x nil)
		0
		(+ 1 (compte (cdr x))
	)
)
(compte (list 1 2 3 4 5 6))



(defun compte(x) (if x (+ 1 (compte (cdr x))) 0)) (compte (list 1 2 3 4 5 6))







(defun ieme(l i)
	(if(l)
		(if (> i 1)
			(car l)
			(ieme (cdr l) (- i 1))
		)
		'"error"
	)
)
