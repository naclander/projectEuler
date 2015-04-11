fib limit x
    | x <= []           = fib limit [1,1]
	| last x > limit    = x 
	| otherwise         = fib limit $ x ++ [rev!!0 + rev!!1] where rev = reverse x

main = print $ sum $ filter even $ fib 4000000 []
