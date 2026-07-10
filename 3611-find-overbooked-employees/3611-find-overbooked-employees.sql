SELECT
    e.employee_id,
    e.employee_name,
    e.department,
    COUNT(*) AS meeting_heavy_weeks
FROM (
    SELECT
        employee_id,
        YEAR(meeting_date) AS yr,
        WEEK(meeting_date, 1) AS wk,
        SUM(duration_hours) AS total_hours
    FROM meetings
    GROUP BY employee_id, YEAR(meeting_date), WEEK(meeting_date, 1)
) w
JOIN employees e
ON e.employee_id = w.employee_id
WHERE total_hours > 20
GROUP BY
    e.employee_id,
    e.employee_name,
    e.department
HAVING COUNT(*) >= 2
ORDER BY
    meeting_heavy_weeks DESC,
    employee_name ASC;