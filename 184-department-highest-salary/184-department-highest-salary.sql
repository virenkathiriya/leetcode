# Write your MySQL query statement below
SELECT 
    d.name Department,
    e.name Employee,
    e.salary
FROM 
    Employee e JOIN Department d
    on e.departmentId = d.id
WHERE 
    (e.departmentId, e.Salary) 
IN (
    SELECT 
        DepartmentId, 
        MAX(Salary) 
    FROM 
        EMPLOYEE 
    GROUP BY DepartmentId
);