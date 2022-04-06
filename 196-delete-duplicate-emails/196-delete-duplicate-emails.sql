# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE p1 from Person p1 JOIN Person p2 ON p1.email = p2.email WHERE p1.Id > p2.Id;