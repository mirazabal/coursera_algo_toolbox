-- by Kirill Elagin

import Control.Monad (replicateM)

compare_func :: Ordering -> Ordering -> Ordering
compare_func a b
         | a < b = LT
         | otherwise = GT

sortLines :: [(Int, Int)] -> [(Int, Int)]
sortLines (x:xs) 
         | fst a < fst b = LT
         | fst a == fst b = compare_func snd a snd b 
         | otherwise = GT

commonPoints :: [(Int, Int)] -> (Int, Int) -> [Int]
commonPoints [] common = fst common
commonPoints (x:xs) common 
        | fst x > snd common = commonPoints xs x  ++ snd common 
        | fst x >= fst common = if snd x < snd common    
                                then commonPoints xs (fst x, snd common) 
                                else commonPoints xs (fst x, snd x)
        | otherwise = commonPoints xs common 


optimal_points :: [(Int, Int)] -> [Int]
optimal_points segments = 
          let sortedLines = sortLines segments
              points = commonPoints tail sortedLines head sortedLines 
          in points
--map fst segments -- write your code here


--sortBy xxx [1,2,3,4,5,6,7]


main :: IO ()
main = do
  n' <- getLine
  let n = read n'
  segments <- replicateM n $ fmap ((\[s, e] -> (read s, read e)) . words) getLine
  let points = optimal_points segments
  print $ length points
  putStrLn $ unwords (map show points)
