-- by Kirill Elagin

import Control.Monad (replicateM)
import Numeric (showFFloat)

import Data.Function (on)
import Data.List (sortBy)

type Item = (Int, Int)

foo :: Int -> Int -> Double
foo a b = fromIntegral(a) / fromIntegral(b)

fooItem ::  Item -> Double
fooItem item = fromIntegral( fst(item)) / fromIntegral( snd(item))

get_optimal_value :: Int -> [Item] -> Double
get_optimal_value 0 _ = 0 
get_optimal_value capacity (x:xs) 
  | capacity > snd(x) =  fromIntegral (fst(x)) +  get_optimal_value (capacity-snd(x)) xs
  | otherwise = (fromIntegral capacity) * fooItem x   


main :: IO ()
main = do
  [n', capacity'] <- fmap words getLine
  let (n, capacity) = (read n', read capacity')
  items <- replicateM n $ fmap ((\[v, w] -> (read v, read w)) . words) getLine

  let sortItems = sortBy ( (flip compare) `on` fooItem ) items  
  printFloat $ get_optimal_value capacity sortItems
 where
  printFloat x = putStrLn $ showFFloat (Just 4) x ""

