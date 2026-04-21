select child.ID ID, child.GENOTYPE GENOTYPE, parent.GENOTYPE PARENT_GENOTYPE
from ecoli_data child
join ecoli_data parent
on child.parent_id = parent.id
where child.GENOTYPE & parent.GENOTYPE = parent.GENOTYPE
order by child.ID asc