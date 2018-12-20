%% Import csv files, and extract necesarry data: 

GW_olav = csvread('trt-olav-loragw01 19.11.2018.csv');
GW_samf =  csvread('trt-samf-loragw01 19.11.2018.csv');
GW_sluppen =  csvread('trt-sluppen-loragw01 19.11.2018.csv');
GW_vm =  csvread('trt-vm-loragw01 19.11.2018.csv');

t_olav = datetime(GW_olav(:,2), 'ConvertFrom', 'posixtime','TimeZone','Europe/Oslo');
t_samf =  datetime(GW_samf(:,2), 'ConvertFrom', 'posixtime','TimeZone','Europe/Oslo');
t_sluppen =  datetime(GW_sluppen(:,2), 'ConvertFrom', 'posixtime','TimeZone','Europe/Oslo');
t_vm =  datetime(GW_vm(:,2), 'ConvertFrom', 'posixtime','TimeZone','Europe/Oslo');

olav_dist = [6.994, 7.595,5.792, 4.26, 2.125, 0.4236, 0.3931];
samf_dist = [6.394, 7.086, 5.156,3.577, 1.276, 1.051, 1.515];
sluppen_dist = [6.946, 7.769, 5.79, 4.46, 3.045, 3.832, 4.283];


t_studenthytta_start = datetime('2018-11-19 10:45:00','TimeZone','Europe/Oslo');
t_studenthytta_stopp = datetime('2018-11-19 11:30:00','TimeZone','Europe/Oslo');
t_graakallen_stopp = datetime('2018-11-19 12:26:00','TimeZone','Europe/Oslo');
t_parkering_stopp = datetime('2018-11-19 13:09:00','TimeZone','Europe/Oslo');
t_utsikten_stopp = datetime('2018-11-19 14:11:00','TimeZone','Europe/Oslo');
t_stiftsgaarden_stopp = datetime('2018-11-19 14:32:00','TimeZone','Europe/Oslo');
t_sentralstasjon_stopp = datetime('2018-11-19 14:46:00','TimeZone','Europe/Oslo');


olav_num_array = zeros(6,6);
olav_dr_set = zeros(6,12);
for i=1:length(t_olav)
    if (t_olav(i)>t_studenthytta_start &&  t_olav(i)<t_studenthytta_stopp)   
        olav_num_array(1,GW_olav(i,1)+1) = olav_num_array(1,GW_olav(i,1)+1)+1;
        
        olav_dr_set(GW_olav(i,1)+1,1) = olav_dr_set(GW_olav(i,1)+1,1) + GW_olav(i,3);
        olav_dr_set(GW_olav(i,1)+1,2) = olav_dr_set(GW_olav(i,1)+1,2)+ GW_olav(i,4);
    end
    if (t_olav(i)>t_studenthytta_stopp &&  t_olav(i)<t_graakallen_stopp)
        olav_num_array(2,GW_olav(i,1)+1) = olav_num_array(2,GW_olav(i,1)+1)+1;
        olav_dr_set(GW_olav(i,1)+1,3) = olav_dr_set(GW_olav(i,1)+1,3) + GW_olav(i,3);
        olav_dr_set(GW_olav(i,1)+1,4) = olav_dr_set(GW_olav(i,1)+1,4)+ GW_olav(i,4);
    end
    if (t_olav(i)>t_graakallen_stopp &&  t_olav(i)<t_parkering_stopp)
        olav_num_array(3,GW_olav(i,1)+1) = olav_num_array(3,GW_olav(i,1)+1)+1;
        olav_dr_set(GW_olav(i,1)+1,5) = olav_dr_set(GW_olav(i,1)+1,5) + GW_olav(i,3);
        olav_dr_set(GW_olav(i,1)+1,6) = olav_dr_set(GW_olav(i,1)+1,6)+ GW_olav(i,4);
    end
    if (t_olav(i)>t_parkering_stopp &&  t_olav(i)<t_utsikten_stopp)
        olav_num_array(4,GW_olav(i,1)+1) = olav_num_array(4,GW_olav(i,1)+1)+1;
        olav_dr_set(GW_olav(i,1)+1,7) = olav_dr_set(GW_olav(i,1)+1,7) + GW_olav(i,3);
        olav_dr_set(GW_olav(i,1)+1,8) = olav_dr_set(GW_olav(i,1)+1,8)+ GW_olav(i,4);
    end
    if (t_olav(i)>t_utsikten_stopp &&  t_olav(i)<t_stiftsgaarden_stopp)
        olav_num_array(5,GW_olav(i,1)+1) = olav_num_array(5,GW_olav(i,1)+1)+1;
        olav_dr_set(GW_olav(i,1)+1,9) = olav_dr_set(GW_olav(i,1)+1,9) + GW_olav(i,3);
        olav_dr_set(GW_olav(i,1)+1,10) = olav_dr_set(GW_olav(i,1)+1,10)+ GW_olav(i,4);
    end
    if (t_olav(i)>t_stiftsgaarden_stopp &&  t_olav(i)<t_sentralstasjon_stopp)
        olav_num_array(6,GW_olav(i,1)+1) = olav_num_array(6,GW_olav(i,1)+1)+1;
        olav_dr_set(GW_olav(i,1)+1,11) = olav_dr_set(GW_olav(i,1)+1,11) + GW_olav(i,3);
        olav_dr_set(GW_olav(i,1)+1,12) = olav_dr_set(GW_olav(i,1)+1,12)+ GW_olav(i,4);
    end
end




samf_num_array = zeros(6,6);
samf_dr_set = zeros(6,12);
for i=1:length(t_samf)
    if (t_samf(i)>t_studenthytta_start &&  t_samf(i)<t_studenthytta_stopp)   
        samf_num_array(1,GW_samf(i,1)+1) = samf_num_array(1,GW_samf(i,1)+1)+1;
        samf_dr_set(GW_samf(i,1)+1,1) = samf_dr_set(GW_samf(i,1)+1,1) + GW_samf(i,3);
        samf_dr_set(GW_samf(i,1)+1,2) = samf_dr_set(GW_samf(i,1)+1,2)+ GW_samf(i,4);
    end
    if (t_samf(i)>t_studenthytta_stopp &&  t_samf(i)<t_graakallen_stopp)
        samf_num_array(2,GW_samf(i,1)+1) = samf_num_array(2,GW_samf(i,1)+1)+1;
        samf_dr_set(GW_samf(i,1)+1,3) = samf_dr_set(GW_samf(i,1)+1,3) + GW_samf(i,3);
        samf_dr_set(GW_samf(i,1)+1,4) = samf_dr_set(GW_samf(i,1)+1,4)+ GW_samf(i,4);
    end
    if (t_samf(i)>t_graakallen_stopp &&  t_samf(i)<t_parkering_stopp)
        samf_num_array(3,GW_samf(i,1)+1) = samf_num_array(3,GW_samf(i,1)+1)+1;
        samf_dr_set(GW_samf(i,1)+1,5) = samf_dr_set(GW_samf(i,1)+1,5) + GW_samf(i,3);
        samf_dr_set(GW_samf(i,1)+1,6) = samf_dr_set(GW_samf(i,1)+1,6)+ GW_samf(i,4);
    end
    if (t_samf(i)>t_parkering_stopp &&  t_samf(i)<t_utsikten_stopp)
        samf_num_array(4,GW_samf(i,1)+1) = samf_num_array(4,GW_samf(i,1)+1)+1;
        samf_dr_set(GW_samf(i,1)+1,7) = samf_dr_set(GW_samf(i,1)+1,7) + GW_samf(i,3);
        samf_dr_set(GW_samf(i,1)+1,8) = samf_dr_set(GW_samf(i,1)+1,8)+ GW_samf(i,4);
    end
    if (t_samf(i)>t_utsikten_stopp &&  t_samf(i)<t_stiftsgaarden_stopp)
        samf_num_array(5,GW_samf(i,1)+1) = samf_num_array(5,GW_samf(i,1)+1)+1;
        samf_dr_set(GW_samf(i,1)+1,9) = samf_dr_set(GW_samf(i,1)+1,9) + GW_samf(i,3);
        samf_dr_set(GW_samf(i,1)+1,10) = samf_dr_set(GW_samf(i,1)+1,10)+ GW_samf(i,4);
    end
    if (t_samf(i)>t_stiftsgaarden_stopp &&  t_samf(i)<t_sentralstasjon_stopp)
        samf_num_array(6,GW_samf(i,1)+1) = samf_num_array(6,GW_samf(i,1)+1)+1;
        samf_dr_set(GW_samf(i,1)+1,11) = samf_dr_set(GW_samf(i,1)+1,11) + GW_samf(i,3);
        samf_dr_set(GW_samf(i,1)+1,12) = samf_dr_set(GW_samf(i,1)+1,12)+ GW_samf(i,4);
    end
end


sluppen_num_array = zeros(6,6);
sluppen_dr_set = zeros(6,12);
for i=1:length(t_sluppen)
    if (t_sluppen(i)>t_studenthytta_start &&  t_sluppen(i)<t_studenthytta_stopp)   
        sluppen_num_array(1,GW_sluppen(i,1)+1) = sluppen_num_array(1,GW_sluppen(i,1)+1)+1;
        sluppen_dr_set(GW_sluppen(i,1)+1,1) = sluppen_dr_set(GW_sluppen(i,1)+1,1) + GW_sluppen(i,3);
        sluppen_dr_set(GW_sluppen(i,1)+1,2) = sluppen_dr_set(GW_sluppen(i,1)+1,2)+ GW_sluppen(i,4);
    end
    if (t_sluppen(i)>t_studenthytta_stopp &&  t_sluppen(i)<t_graakallen_stopp)
        sluppen_num_array(2,GW_sluppen(i,1)+1) = sluppen_num_array(2,GW_sluppen(i,1)+1)+1;
        sluppen_dr_set(GW_sluppen(i,1)+1,3) = sluppen_dr_set(GW_sluppen(i,1)+1,3) + GW_sluppen(i,3);
        sluppen_dr_set(GW_sluppen(i,1)+1,4) = sluppen_dr_set(GW_sluppen(i,1)+1,4)+ GW_sluppen(i,4);
    end
    if (t_sluppen(i)>t_graakallen_stopp &&  t_sluppen(i)<t_parkering_stopp)
        sluppen_num_array(3,GW_sluppen(i,1)+1) = sluppen_num_array(3,GW_sluppen(i,1)+1)+1;
        sluppen_dr_set(GW_sluppen(i,1)+1,5) = sluppen_dr_set(GW_sluppen(i,1)+1,5) + GW_sluppen(i,3);
        sluppen_dr_set(GW_sluppen(i,1)+1,6) = sluppen_dr_set(GW_sluppen(i,1)+1,6)+ GW_sluppen(i,4);
    end
    if (t_sluppen(i)>t_parkering_stopp &&  t_sluppen(i)<t_utsikten_stopp)
        sluppen_num_array(4,GW_sluppen(i,1)+1) = sluppen_num_array(4,GW_sluppen(i,1)+1)+1;
        sluppen_dr_set(GW_sluppen(i,1)+1,7) = sluppen_dr_set(GW_sluppen(i,1)+1,7) + GW_sluppen(i,3);
        sluppen_dr_set(GW_sluppen(i,1)+1,8) = sluppen_dr_set(GW_sluppen(i,1)+1,8)+ GW_sluppen(i,4);
    end
    if (t_sluppen(i)>t_utsikten_stopp &&  t_sluppen(i)<t_stiftsgaarden_stopp)
        sluppen_num_array(5,GW_sluppen(i,1)+1) = sluppen_num_array(5,GW_sluppen(i,1)+1)+1;
        sluppen_dr_set(GW_sluppen(i,1)+1,9) = sluppen_dr_set(GW_sluppen(i,1)+1,9) + GW_sluppen(i,3);
        sluppen_dr_set(GW_sluppen(i,1)+1,10) = sluppen_dr_set(GW_sluppen(i,1)+1,10)+ GW_sluppen(i,4);
    end
    if (t_sluppen(i)>t_stiftsgaarden_stopp &&  t_sluppen(i)<t_sentralstasjon_stopp)
        sluppen_num_array(6,GW_sluppen(i,1)+1) = sluppen_num_array(6,GW_sluppen(i,1)+1)+1;
        sluppen_dr_set(GW_sluppen(i,1)+1,11) = sluppen_dr_set(GW_sluppen(i,1)+1,11) + GW_sluppen(i,3);
        sluppen_dr_set(GW_sluppen(i,1)+1,12) = sluppen_dr_set(GW_sluppen(i,1)+1,12)+ GW_sluppen(i,4);
    end
end


mean_dr_set = olav_dr_set+samf_dr_set+sluppen_dr_set;
tot_num_arr = olav_num_array+samf_num_array+sluppen_num_array;
tot_dist = (olav_dist+samf_dist+sluppen_dist)/3;
C = {'k','b','r','g','c',[.5 .6 .7],[.8 .2 .6]}; % Cell array of colros.


%% Plot data

figure(1)
clear title xlabel ylabel
clf
title('Mean RSSI for GW at Olavskvartalet')
hold on
xlabel('Distance [km]')
ylabel('RSSI [dBm]')
for n=1:6
    for i=1:6
        if (olav_num_array(i,n) > 0)
            plot(n,olav_dr_set(i,2*n-1)/olav_num_array(n,i),'mo','color',C{i},'linewidth',2);
        end
    end
end
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz'})


figure(2)
clear title xlabel ylabel
clf
title('Mean SNR compared to distance for GW at Olavskvartalet')
hold on
xlabel('Distance [km]')
ylabel('SNR [dB]')
for n=1:6
    for i=1:6
        if (olav_num_array(i,n) > 0)
            plot(n,olav_dr_set(i,2*n)/olav_num_array(n,i),'mo','color',C{i},'linewidth',2);
        end
    end
end
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz'})


figure(3)
clear title xlabel ylabel
clf
title('Mean RSSI for GW at Samfundet')
hold on
xlabel('Distance [km]')
ylabel('RSSI [dBm]')
for n=1:6
    for i=1:6
        if (samf_num_array(i,n) > 0)
            plot(samf_dist(n),samf_dr_set(i,2*n-1)/samf_num_array(n,i),'mo','color',C{i},'linewidth',2);
        end
    end
end
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz'})


figure(4)
clear title xlabel ylabel
clf
title('Mean SNR compared to distance for GW at Samfundet')
hold on
xlabel('Distance [km]')
ylabel('SNR [dB]')
for n=1:6
    for i=1:6
        if (samf_num_array(i,n) > 0)
            plot(samf_dist(n),samf_dr_set(i,2*n)/samf_num_array(n,i),'mo','color',C{i},'linewidth',2);
        end
    end
end
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz'})


figure(5)
clear title xlabel ylabel
clf
hold on
title('Mean RSSI for GW at Sluppen')
xlabel('Distance [km]')
ylabel('RSSI [dBm]')
for n=1:6
    for i=1:6
        if (sluppen_num_array(i,n) > 0)
            plot(sluppen_dist(n),sluppen_dr_set(i,2*n-1)/sluppen_num_array(n,i),'mo','color',C{i},'linewidth',2);
        end
    end
end
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz'})





figure(6)
clear title xlabel ylabel
clf
hold on
title('Mean SNR compared to distance for GW at Sluppen')
xlabel('Distance [km]')
ylabel('SNR [dB]')
for n=1:6
    for i=1:6
        if (sluppen_num_array(i,n) > 0)
            plot(sluppen_dist(n),sluppen_dr_set(i,2*n)/sluppen_num_array(n,i),'mo','color',C{i},'linewidth',2);
        end
    end
end
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz'})

%% Flat Urban enviromment
figure(7)

clear title xlabel ylabel
clf
subplot(2,1,1)
hold on
title('Mean RSSI in flat urban environment, Sluppen-GW');
xlabel('DR')
ylabel('RSSI [dBm]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-130,-100])
for i=1:6
    if (sluppen_num_array(5,i) > 0)
        plot(i-1,sluppen_dr_set(i,9)/sluppen_num_array(5,i),'mo','color',C{i},'linewidth',2);
        mean = mean + sluppen_dr_set(i,9)/sluppen_num_array(5,i);
    end
end
yline(mean/3);
grid on
%legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'Mean'})

subplot(2,1,2)
hold on
title('Mean RSSI in flat urban environment, Samfundet-GW');
xlabel('DR')
ylabel('RSSI [dBm]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-120,-90])
for i=1:6
    if (samf_num_array(5,i) > 0)
        plot(i-1,samf_dr_set(i,9)/samf_num_array(5,i),'mo','color',C{i},'linewidth',2);
        mean = mean + samf_dr_set(i,9)/samf_num_array(5,i);
    end
end
yline(mean/6);
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz';'Mean'})



figure(8)
clear title xlabel ylabel
clf
subplot(2,1,1)
hold on
title('Mean SNR in flat urban environment, Sluppen-GW');
xlabel('DR')
ylabel('SNR [dB]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-15,15])
for i=1:6
    if (sluppen_num_array(5,i) > 0)
        plot(i-1,sluppen_dr_set(i,10)/sluppen_num_array(5,i),'mo','color',C{i},'linewidth',2);
        mean = mean + sluppen_dr_set(i,10)/sluppen_num_array(5,i);
    end
end
yline(mean/3);
grid on
%legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'Mean'})

subplot(2,1,2)
hold on
title('Mean SNR in flat urban environment, Samfundet-GW');
xlabel('DR')
ylabel('SNR [dB]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-15,15])
for i=1:6
    if (samf_num_array(5,i) > 0)
        plot(i-1,samf_dr_set(i,10)/samf_num_array(5,i),'mo','color',C{i},'linewidth',2);
        mean = mean + samf_dr_set(i,10)/samf_num_array(5,i);
    end
end
yline(mean/6);
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz';'Mean'})








%% Plots for the mean on each test-site


figure(11)
clear title xlabel ylabel
clf
hold on
title('Mean RSSI Compared to distance')
xlabel('Distance [km]')
ylabel('RSSI [dBm]')
set(gca,'ylim',[-120,-80])
for n=1:6
    for i=1:6
        if (tot_num_arr(i,n) > 0)
           plot(tot_dist(n),mean_dr_set(i,2*n-1)/tot_num_arr(n,i),'mo','color',C{i},'linewidth',2);
        end
    end
end
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz'})


figure(12)
clear title xlabel ylabel
clf
hold on
title('Mean SNR compared to distance')
xlabel('Distance [km]')
ylabel('SNR [dB]')
set(gca,'ylim',[-11,11])
for n=1:6
    for i=1:6
        if (tot_num_arr(i,n) > 0)
           plot(tot_dist(n),mean_dr_set(i,2*n)/tot_num_arr(n,i),'mo','color',C{i},'linewidth',2);
        end
    end
end
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz'})


figure(13)
clear title xlabel ylabel
clf
subplot(2,1,1)
hold on
title('Mean RSSI at StudentHytta');
xlabel('DR')
ylabel('RSSI [dBm]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-120,-80])
for i=1:6
    if (tot_num_arr(1,i) > 0)
        plot(i-1,mean_dr_set(i,1)/tot_num_arr(1,i),'mo','color',C{i},'linewidth',2);
        mean = mean + mean_dr_set(i,1)/tot_num_arr(1,i);
    end
end
yline(mean/6);
grid on
%legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz';'Mean'})


subplot(2,1,2)
hold on
title('Mean SNR at StudentHytta');
xlabel('DR')
ylabel('SNR [dB]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-11,11])
for i=1:6
    if (tot_num_arr(1,i) > 0)
        plot(i-1,mean_dr_set(i,2)/tot_num_arr(1,i),'mo','color',C{i},'linewidth',2);
        mean = mean + mean_dr_set(i,2)/tot_num_arr(1,i);
    end
end
yline(mean/6);
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz';'Mean'})


figure(14)
clear title xlabel ylabel
clf
subplot(2,1,1)
hold on
title('Mean RSSI at Graakallen');
xlabel('DR')
ylabel('RSSI [dBm]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-120,-80])
for i=1:6
    if (tot_num_arr(2,i) > 0)
        plot(i-1,mean_dr_set(i,3)/tot_num_arr(2,i),'mo','color',C{i},'linewidth',2);
        mean = mean + mean_dr_set(i,3)/tot_num_arr(2,i);
    end
end
yline(mean/6);
grid on
%legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz';'Mean'})


subplot(2,1,2)
hold on
title('Mean SNR at Graakallen');
xlabel('DR')
ylabel('SNR [dB]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-11,11])
for i=1:6
    if (tot_num_arr(2,i) > 0)
        plot(i-1,mean_dr_set(i,4)/tot_num_arr(2,i),'mo','color',C{i},'linewidth',2);
        mean = mean + mean_dr_set(i,4)/tot_num_arr(2,i);
    end
end
yline(mean/6);
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz';'Mean'})


figure(15)
clear title xlabel ylabel
clf
subplot(2,1,1)
hold on
title('Mean RSSI at ParkingLot');
xlabel('DR')
ylabel('RSSI [dBm]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-120,-80])
for i=1:6
    if (tot_num_arr(3,i) > 0)
        plot(i-1,mean_dr_set(i,5)/tot_num_arr(3,i),'mo','color',C{i},'linewidth',2);
        mean = mean + mean_dr_set(i,5)/tot_num_arr(3,i);
    end
end
yline(mean/6);
grid on
%legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz';'Mean'})


subplot(2,1,2)
hold on
title('Mean SNR at ParkingLot');
xlabel('DR')
ylabel('SNR [dB]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-11,11])
for i=1:6
    if (tot_num_arr(3,i) > 0)
        plot(i-1,mean_dr_set(i,6)/tot_num_arr(3,i),'mo','color',C{i},'linewidth',2);
        mean = mean + mean_dr_set(i,6)/tot_num_arr(3,i);
    end
end
yline(mean/6);
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz';'Mean'})


figure(16)
clear title xlabel ylabel
clf
subplot(2,1,1)
hold on
title('Mean RSSI at Utsikten');
xlabel('DR')
ylabel('RSSI [dBm]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-120,-80])
for i=1:6
    if (tot_num_arr(4,i) > 0)
        plot(i-1,mean_dr_set(i,7)/tot_num_arr(4,i),'mo','color',C{i},'linewidth',2);
        mean = mean + mean_dr_set(i,7)/tot_num_arr(4,i);
    end
end
yline(mean/6);
grid on
%legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz';'Mean'})


subplot(2,1,2)
hold on
title('Mean SNR at Utsikten');
xlabel('DR')
ylabel('SNR [dB]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-11,11])
for i=1:6
    if (tot_num_arr(4,i) > 0)
        plot(i-1,mean_dr_set(i,8)/tot_num_arr(4,i),'mo','color',C{i},'linewidth',2);
        mean = mean + mean_dr_set(i,8)/tot_num_arr(4,i);
    end
end
yline(mean/6);
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz';'Mean'})


figure(17)
clear title xlabel ylabel
clf
subplot(2,1,1)
hold on
title('Mean RSSI at Stiftsgaarden');
xlabel('DR')
ylabel('RSSI [dBm]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-120,-80])
for i=1:6
    if (tot_num_arr(5,i) > 0)
        plot(i-1,mean_dr_set(i,9)/tot_num_arr(5,i),'mo','color',C{i},'linewidth',2);
        mean = mean + mean_dr_set(i,9)/tot_num_arr(5,i);
    end
end
yline(mean/6);
grid on
%legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz';'Mean'})

subplot(2,1,2)
hold on
title('Mean SNR at Stiftsgaarden');
xlabel('DR')
ylabel('SNR [dB]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-11,11])
for i=1:6
    if (tot_num_arr(5,i) > 0)
        plot(i-1,mean_dr_set(i,10)/tot_num_arr(5,i),'mo','color',C{i},'linewidth',2);
        mean = mean + mean_dr_set(i,10)/tot_num_arr(5,i);
    end
end
yline(mean/6);
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz';'Mean'})



figure(18)

clear title xlabel ylabel
clf
subplot(2,1,1)
hold on
title('Mean RSSI at CentralStation');
xlabel('DR')
ylabel('RSSI [dBm]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-120,-80])

for i=1:6
    if (tot_num_arr(6,i) > 0)
        plot(i-1,mean_dr_set(i,11)/tot_num_arr(6,i),'mo','color',C{i},'linewidth',2);
        mean = mean + mean_dr_set(i,11)/tot_num_arr(6,i);
    end
end
yline(mean/6);
grid on



subplot(2,1,2)

hold on
title('Mean SNR at CentralStation');
xlabel('DR')
ylabel('SNR [dB]')
mean = 0;
set(gca,'xtick',0:5)
set(gca,'xlim',[0,5])
set(gca,'ylim',[-11,11])
for i=1:6
    if (tot_num_arr(6,i) > 0)
        plot(i-1,mean_dr_set(i,12)/tot_num_arr(6,i),'mo','color',C{i},'linewidth',2);
        mean = mean + mean_dr_set(i,12)/tot_num_arr(6,i);
    end
end
yline(mean/6);
grid on
legend({'SF12@125KHz';'SF11@125KHz';'SF10@125KHz';'SF9@125KHz';'SF8@125KHz';'SF7@125KHz';'Mean'})

%}



