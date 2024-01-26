-- 코드를 입력하세요
SELECT O.ANIMAL_ID, O.NAME
FROM ANIMAL_OUTS AS O
LEFT JOIN ANIMAL_INS AS I
USING(ANIMAL_ID)
WHERE ISNULL(I.ANIMAL_TYPE)
ORDER BY O.ANIMAL_ID