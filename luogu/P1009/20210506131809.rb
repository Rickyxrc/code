def jiec(val)
    i=1
    s=1
    while i<=val do
        s=s*i
        i=i+1
    end
    return s
end
inp1=gets.chomp.to_i
i=1
s=0
while i<=inp1 do
   s+=jiec(i) 
   i=i+1
end
print s