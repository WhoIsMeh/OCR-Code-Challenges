local wordsDigits = {
    
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
    
}
local wordsTens = {
    
    "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    
}

function numToWord(num)
    
   local hundreds = math.floor(num / 100 % 10)
   local flat = num % 100
   
   print(hundreds)
   print(flat)
   
   local string = ""
   
   if hundreds > 0 then
       
       string = string .. wordsDigits[hundreds] .. " hundred"
       
   end
   
   if flat > 0 then
       
       if string.Length ~= nil then
           
           string = string .. " "
           
       end
       
       if flat < 20 then
           
           string = string .. wordsDigits[flat]
           
       else
           
           local tens = tonumber(string.sub(flat, 1, 1))
           local units = tonumber(string.sub(flat, 2, 2))
           
           print(tens)
           print(units)
           
           string = string .. wordsTens[tens - 1]
           
           if units > 0 then
               
               string = string .. "-" .. wordsDigits[units]
           
           end
           
       end
       
   end
   
   return(string)
   
end
