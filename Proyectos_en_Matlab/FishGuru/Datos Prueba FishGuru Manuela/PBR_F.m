function [xmax, x01] = PBR_F(F,M,W,x0)

f1 = @(x) NYR_TB(x);
f2 = @(x) (dYR_TB(x)-0.1*dYR_TB(0));

xmax = fminbnd(@(x) f1(x),0,10);
x01 = fzero(f2,x0); 
    
    % (-Y/R)
    function y = NYR_TB(x)
        p = exp(-(x.*F)- M);
        G = (x.*F)./((x.*F)+ M);
        k = length(F);
        aux = 1;
        sum = 0;
        for i=1:k-1,
        sum = sum + G(i)*(1-p(i))*aux*W(i);
        aux = aux*p(i); 
        end
        sum = sum + G(k)*aux*W(k);
        y = -sum;
    end

    % (Y/R)'
    function y = dYR_TB(x) 
    p = exp(-(x.*F)- M);
    G = (x.*F)./((x.*F)+ M);
    dG =  (F.*M)./(((x.*F)+M).*((x.*F)+M));
    daux = 1;
    dsum = 0;
    sumF = 0;
    k = length(F);
    for i=1:k-1,
        dsum = dsum + (G(i)*F(i)*p(i)+(dG(i)-G(i)*sumF)*(1-p(i)))*W(i)*daux;
        sumF = sumF + F(i);
        daux = daux*p(i);
    end
    dsum = dsum + (dG(k)-G(k)*sumF)*W(k)*daux;
    y = dsum;
    end
end

