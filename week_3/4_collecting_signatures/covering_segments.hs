-- by Kirill Elagin

import Control.Monad (replicateM)

compare_func :: Ordering -> Ordering -> Ordering
compare_func a b
         | a < b = LT
         | otherwise = GT

quicksort :: (Ord a) => [(a,a)] -> [(a,a)]
quicksort [] = []
quicksort (x:xs) = quicksort [y | y <- xs, y <= x] ++ [x] ++ quicksort [y | y <- xs, y > x]


commonPoints :: [(Int, Int)] -> (Int, Int) -> [Int]
commonPoints [] common = return (fst common) 
commonPoints (x:xs) common 
        | fst x > snd common = (snd common):commonPoints xs x  
        | fst x >= fst common = if snd x < snd common    
                                then commonPoints xs (fst x, snd x) 
                                else commonPoints xs (fst x, snd common)
        | otherwise = commonPoints xs common 

optimal_points :: [(Int, Int)] -> [Int]
optimal_points segments = --quicksort segments
          let sortedLines = quicksort segments
					in	commonPoints (tail sortedLines) (head sortedLines)

main :: IO ()
main = do
  n' <- getLine
  let n = read n'
  segments <- replicateM n $ fmap ((\[s, e] -> (read s, read e)) . words) getLine
  let points = optimal_points segments
  print $ length points
  putStrLn $ unwords (map show points)
