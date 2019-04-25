-- by Kirill Elagin

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = quicksort [y | y <- xs, y <= x] ++ [x] ++ quicksort [y | y <- xs, y > x]

acc :: [Int] -> Integer
acc [] = 0
acc (x:xs) = toInteger x + acc xs


max_dot_product :: [Int] -> [Int] -> Integer
max_dot_product as bs =
	let sort_as = quicksort as
	    sort_bs = quicksort bs 
	    mult_lst = zipWith (*) sort_as sort_bs 
	in acc mult_lst
-- result -- write your code here

main :: IO ()
main = do
  _  <- getLine
  as <- fmap (map read . words) getLine
  bs <- fmap (map read . words) getLine
  print $ max_dot_product as bs
