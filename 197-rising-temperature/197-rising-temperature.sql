# Write your MySQL query statement below
SELECT 
    w.id
FROM
    Weather w
JOIN
    Weather s
ON 
    DATEDIFF(w.recordDate, s.recordDate) = 1
    AND w.Temperature > s.Temperature; 