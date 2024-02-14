-- 코드를 입력하세요
SELECT ANIMAL_ID, I.ANIMAL_TYPE, I.NAME
FROM ANIMAL_INS AS I
JOIN ANIMAL_OUTS AS O
    USING(ANIMAL_ID)
WHERE I.SEX_UPON_INTAKE LIKE "INTACT%"
    && (O.SEX_UPON_OUTCOME LIKE "NEUTERED%" || O.SEX_UPON_OUTCOME LIKE"SPAYED%")
ORDER BY ANIMAL_ID