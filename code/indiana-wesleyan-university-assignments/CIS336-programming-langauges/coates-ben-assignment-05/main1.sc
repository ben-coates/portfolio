; Benjamin Coates
; Programming Languages
; Functional Languages
; Problem 4
; FA 2015
; main1.sc

(define (x n lis)
       (cond
            ((null? lis) '())
            ((equal? n (car lis)) (x n (cdr lis)))
            (else (cons (car lis) (x n (cdr lis))))
       )
)

(display (x 2 '( 1 2 3 2 4 2 5 2)))
(newline)