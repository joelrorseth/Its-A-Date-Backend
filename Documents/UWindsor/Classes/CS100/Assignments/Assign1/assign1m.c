p1 = "1"

p2 = "Ryan Pearson"

p3  x = x + 1

p4 x y = x, if x <= y
= y, if y < x

p5 xs = map (^2) xs

p6 (x:xl) = x

p7 = foldr (*)1

p8 0 = 1
p8 n = n * p8(n-1)

p9 xs ys = xs -- (xs -- ys)

p10 (x,y) = x

p11 x = x - 1

p12 =  foldr(+)0 . map p10

