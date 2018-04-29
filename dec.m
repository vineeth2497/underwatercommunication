clc;
close all
clear all
global R1;
global G1;
global B1;
global code ;
global j;
j = 1;
    %Initialise video capturing object
    
  
   
    for i=0:10
    mycam=webcam(1);
    mycam.Brightness = -50;
    % Get the snapshot of the current frame
    IMRED = snapshot(mycam);
    %IMRED= imread('8.jpeg');
    % we have to subtract the red green and blue component. 
    % from the grayscale image to extract the Red components in the image.
    diff_im = imsubtract(IMRED(:,:,1), rgb2gray(IMRED));
    gr=graythresh(diff_im);
    
    % from the grayscale image to extract the Green components in the image.
    diff_im2 = imsubtract(IMRED(:,:,2), rgb2gray(IMRED));
    gr2=graythresh(diff_im2);
    
    % from the grayscale image to extract the Blue components in the image.
    diff_im3 = imsubtract(IMRED(:,:,3), rgb2gray(IMRED));
    gr3=graythresh(diff_im3);
     
    %Median filter IS USED to filter out noise
     diff_im = medfilt2(diff_im, [3 3]);
     diff_im2 = medfilt2(diff_im2, [3 3]);
     diff_im3 = medfilt2(diff_im3, [3 3]);
   % Convert the resulting grayscale image into a binary image.
    diff_im = im2bw(diff_im,.24);
    diff_im2 = im2bw(diff_im2,.09);
    diff_im3 = im2bw(diff_im3,.15);
    imshow(diff_im)
    
    
    % Remove all those pixels less than px
    diff_im = bwareaopen(diff_im,600);
    diff_im2 = bwareaopen(diff_im2,100);
    diff_im3 = bwareaopen(diff_im2,1000);
   
    % Label all the connected components in the image
    %and also count the number of red objects in frame
    [bw ,bw1] = bwlabel(diff_im, 8);
    [bg ,bg1] = bwlabel(diff_im2, 8);
    [bl ,bl1] = bwlabel(diff_im3, 8);
    cc = bwconncomp(diff_im,8);
    rednm = cc.NumObjects;
     cc2 = bwconncomp(diff_im2,8);
    greennm = cc2.NumObjects;
     cc3 = bwconncomp(diff_im3,8);
    bluenm = cc3.NumObjects;
    disp(rednm);
    disp(greennm);
    disp(bluenm);
   %disp('Number of objects red detected: ' sum2str(bw1));
   % We get a set of properties for each labeled region.
    stats = regionprops(bw, 'BoundingBox', 'Centroid');
    stats2 = regionprops(bg, 'BoundingBox', 'Centroid');
    stats3 = regionprops(bl, 'BoundingBox', 'Centroid');
    
    % Display the image
    imshow( IMRED );
    
    hold on
    R1=[0 0 0 0 0];
    G1=[0 0 0 0 0];
    B1=[0 0 0 0 0];
    %This is a loop to bound the red objects in a rectangular box.
     for object = 1:length(stats)
         bb = stats(object).BoundingBox;
         bc = stats(object).Centroid;
         rectangle('Position',bb,'EdgeColor','r','LineWidth',2)
         plot(bc(1),bc(2), '-m+')
         a=text(bc(1)+15,bc(2), strcat('X: ', num2str(round(bc(1))), '    Y: ', num2str(round(bc(2)))));
         set(a, 'FontName', 'Arial', 'FontWeight', 'bold', 'FontSize', 12, 'Color', 'yellow');
         Xr=round(bc(1));
        disp(Xr);
        if rednm==2
            if(Xr > 400)
            R1=[0 0 0 0 1];
            else
             R1=[0 1 0 0 1];
            end
        elseif rednm==1
                if(Xr < 170)
                    R1 = [0 0 0 0 1];
                else
                    R1= [0 1 0 0 0];
                end    
        end
        
               
         
     end  
     for object2 = 1:length(stats2)
         bb2 = stats2(object2).BoundingBox;
         bc2 = stats2(object2).Centroid;
         rectangle('Position',bb2,'EdgeColor','r','LineWidth',2)
         plot(bc2(1),bc2(2), '-m+')
         a=text(bc2(1)+15,bc2(2), strcat('X: ', num2str(round(bc2(1))), '    Y: ', num2str(round(bc2(2)))));
         set(a, 'FontName', 'Arial', 'FontWeight', 'bold', 'FontSize', 12, 'Color', 'yellow');
        
         
        if greennm==2
           G1 = [0 0 1 0 0];
        elseif greennm==1
            G1 = [0 0 1 0 0];
        elseif greennm==3 
             G1 = [0 0 1 0 0];
        else G1 = [0 0 0 0 0];
         end
         
     end  
    for  object3 = 1:length(stats3)
         bb3 = stats3(object3).BoundingBox;
         bc3 = stats3(object3).Centroid;
         rectangle('Position',bb3,'EdgeColor','r','LineWidth',2)
         plot(bc3(1),bc3(2), '-m+')
         a=text(bc3(1)+15,bc3(2), strcat('X: ', num2str(round(bc3(1))), '    Y: ', num2str(round(bc3(2)))));
         set(a, 'FontName', 'Arial', 'FontWeight', 'bold', 'FontSize', 12, 'Color', 'yellow');
         Xb=round(bc3(1));
         disp(Xb);
    if bluenm == 2
                B1 = [1 0 0 1 0];
          elseif bluenm == 1
                if (Xb < 280)
                    B1 = [0 0 0 1 0];
                else B1=[1 0 0 0 0];
                end
          else B1 = [0 0 0 0 0];
        end
    end
    
    disp(R1);
    disp(G1); 
    disp(B1);
    C=R1+G1+B1;
    disp(C);
  
    
    if C == [0 0 0 0 1]
        disp('a');
        code(j) = 'a';
        j = j +1;
    elseif C == [0 0 0 1 0]
        disp('b');
        code(j) = 'b';
        j = j +1;
    elseif C == [0 0 0 1 1]
        disp('c');
        code(j) = 'c';
        j = j +1;
    elseif C == [0 0 1 0 0]
        disp('d');
        code(j) = 'd';
        j = j +1;
    elseif C == [0 0 1 0 1]
        disp('e');
        code(j) = 'e';
        j = j +1;
    elseif C == [0 0 1 1 0]
        disp('f');
        code(j) = 'f';
        j = j +1;
    elseif C == [0 0 1 1 1]
        disp('g');
        code(j) = 'g';
        j = j +1;
    elseif C == [0 1 0 0 0]
        disp('h');
        code(j) = 'h';
        j = j +1;
    elseif C == [0 1 0 0 1]
        disp('i');
        code(j) = 'i';
        j = j +1;
    elseif C == [0 1 0 1 0]
        disp('j');
        code(j) = 'j';
        j = j +1;
    elseif C == [0 1 0 1 1]
        disp('k');
        code(j) = 'k';
        j = j +1;
    elseif C == [0 1 1 0 0]
        disp('l');
        code(j) = 'l';
        j = j +1;
    elseif C == [0 1 1 0 1]
        disp('m');
        code(j) = 'm';
        j = j +1;
    elseif C == [0 1 1 1 0]
        disp('n');
        code(j) = 'n';
        j = j +1;
    elseif C == [0 1 1 1 1]
        disp('o');
        code(j) = 'o';
        j = j +1;
    elseif C == [1 0 0 0 0]
        disp('p');
        code(j) = 'p';
        j = j +1;
    elseif C == [1 0 0 0 1]
        disp('q');
        code(j) = 'q';
        j = j +1;
    elseif C == [1 0 0 1 0]
        disp('r');
        code(j) = 'r';
        j = j +1;
    elseif C == [1 0 0 1 1]
        disp('s');
        code(j) = 's';
        j = j +1;
    elseif C == [1 0 1 0 0]
        disp('t');
        code(j) = 't';
        j = j +1;
    elseif C == [1 0 1 0 1]
        disp('u');
        code(j) = 'u';
        j = j +1;
    elseif C == [1 0 1 1 0]
        disp('v');
        code(j) = 'v';
        j = j +1;
    elseif C == [1 0 1 1 1]
        disp('w');
        code(j) = 'w';
        j = j +1;
    elseif C == [1 1 0 0 0]
        disp('x');
        code(j) = 'x';
        j = j +1;
    elseif C == [1 1 0 0 1]
        disp('y');
        code(j) = 'y';
        j = j +1;
    elseif C == [1 1 0 1 0]
        disp('z');
        code(j) = 'z';
        j = j +1;
        else disp('error'); 
         code(j) ='*';
         j = j +1;
    end    
    
    
    hold off
   
   pause(1.2)
   clear mycam;
   
  end
disp (char(code));
clear all;

