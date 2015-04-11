divisible x = ((x `mod` 3) == 0) || ((x `mod` 5) == 0)
main = print $ sum $ takeWhile (<1000) $ filter divisible [1..]
