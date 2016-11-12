; Benjamin Coates
; Programming Languages
; Functional Languages
; Problem 6
; FA 2015
; main3.sc

(define (x n lis)
       (cond
            ((null? lis) '())
            ((not (list? (car lis)))
                (cond
                    ((equal? n (car lis)) (x n (cdr lis)))
                    (else (cons (car lis) (x n (cdr lis))))))
            (else (cons (x n (car lis)) (x n (cdr lis))))
       )
)

(display (x 4 '( 1 (2 (4 5 2) 3) 4 5)))
(newline)
