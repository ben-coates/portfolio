; Benjamin Coates
; Programming Languages
; Functional Languages
; Problem 5
; FA 2015
; main2.sc

(define (x n lis)
       (cond
            ((null? lis) '())
            ((equal? n (car lis)) (x n (cdr lis)))
            (else (cons (car lis) (x n (cdr lis))))
       )
)

(display (x 2 '( 1 2 (2 3) 3 4 5)))
(newline)