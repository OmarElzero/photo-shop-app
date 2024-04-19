#ifndef FILTERS_H
#define FILTERS_H

/*
 * Filters.h : Header File contain All the filters
 * Filter 1  : Gray Scale
 * Filter 2  : Black & White
 * Filter 3  : Invert
 * Filter 4  : Merge
 * Filter 5  : Flip
 * Filter 6  : Rotate
 * Filter 7  : Darken & Lighten
 * Filter 8  : Crop
 * Filter 9  : Frame
 * Filter 10 : Detect Edges
 * Filter 11 : Resize
 * Filter 12 : Blur
 * Filter 13 : Wanuo
 * Filter 14 : Oilpainting
 * Filter 15 :  Old TV
 * Filter 16 : Purple
 * Filter 17 : Inferared
 * Filter 18 : Skew
 * Filter 19 : Demon
 * Filter 20 : Zompie (rand)
 *
*/
#include "Image_Class.h"
#include "mainwindow.h"

QString save = "saved.jpg";
Image imge;


/*
 * @brief function to implement converting from photo color to gray scale
 *
 * @param filename - image we are going to load
 * @return - return an Gray Scale Image
 */
Image gray_scale(string img_name) {
    Image img(img_name) ;
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            int avr = (img(i, j, 0) + img(i, j, 1) + img(i, j, 2)) / 3 ;
            for (int k = 0; k < 3; ++k) {
                img(i,j,k) = avr ;
            }
        }
    }
    img.saveImage(save.toStdString());
    return img ;
}
/*
 * @brief function to implement converting from photo color to gray scale then Black And White
 *
 * @param filename - image we are going to load
 * @return - return an Image colored with Black and White
 */
Image Black_White(const QString& filename) {

    std::string filename_std = filename.toStdString();
    Image image(filename_std);

    unsigned int threshold = 128;

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            unsigned int value = (avg < threshold) ? 0 : 255;

            image(i, j, 0) = value;
            image(i, j, 1) = value;
            image(i, j, 2) = value;
        }
    }

    image.saveImage(save.toStdString());
    return image;
}
/*
 * @brief function to implement Inverting Photo colors
 *
 * @param filename - image we are going to Invert
 * @return - return an Inverted Image
 */
Image invertColors( string filename) {
    Image img(filename);
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            int red = img(i, j, 0);
            int green = img(i, j, 1);
            int blue = img(i, j, 2);
            red = 255 - red;
            green = 255 - green;
            blue = 255 - blue;
            img(i, j, 0) = red;
            img(i, j, 1) = green;
            img(i, j, 2) = blue;
        }
    }
    img.saveImage(save.toStdString());
    return img;
}
/*
 * @brief function to implement Merging Two Photo
 *
 * @param img1_name - image we are going to merge
 * @param img2_name - second image we are going to merge
 * @return - return a Merged Image
 */
Image merging_images_filter(string img1_name , string img2_name ) {
    Image img1(img1_name);
    Image img2(img2_name);
    bool flag = true;
    int wid, hig;
    if (img1.width > img2.width || img1.height > img2.height) {
        flag = false;
        wid = img1.width, hig = img1.height;
    } else {
        flag = true;
        wid = img2.width, hig = img2.height;
    }

    Image resized_img(wid, hig);
    for (int i = 0; i < wid; i++) {
        for (int j = 0; j < hig; j++) {
            int original_x, original_y;
            if (!flag) {
                original_x = i * img2.width / img1.width;
                original_y = j * img2.height / img1.height;
            } else {
                original_x = i * img1.width / img2.width;
                original_y = j * img1.height / img2.height;
            }
            for (int k = 0; k < 3; ++k) {
                if (!flag)
                    resized_img(i, j, k) = img2(original_x, original_y, k);
                else
                    resized_img(i, j, k) = img1(original_x, original_y, k);
            }
        }
    }
    for (int i = 0; i < resized_img.width; ++i) {
        for (int j = 0; j < resized_img.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (!flag) {
                    resized_img(i, j, k) -= resized_img(i, j, k) / 2;
                    resized_img(i, j, k) += img1(i, j, k) / 2;
                } else {
                    resized_img(i, j, k) -= resized_img(i, j, k) / 2;
                    resized_img(i, j, k) += img2(i, j, k) / 2;
                }
            }
        }
    }
    resized_img.saveImage(save.toStdString());
    return resized_img ;
}
/*
 * @brief function to implement fliping  photo Heroziontaliy
 *
 * @param filename - image we are going to load
 * @return - return an Image filped Heroziontaliy
 */
Image flip_H(string filename) {


    Image image(filename);
    Image image2(image.width,image.height);


    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j <image.height; ++j) {
            int flip = image.height-1-j;
            image2(i, flip, 0) =image(i, j, 0) ;
            image2(i, flip, 1) =image(i, j, 1) ;
            image2(i, flip, 2) = image(i, j, 2);
        }
    }

    image2.saveImage(save.toStdString());
    return image2;
}
/*
 * @brief function to implement fliping  photo vertacily
 *
 * @param filename - image we are going to load
 * @return - return an Image filped vertacily
 */
Image flip_V(string filename) {


    Image image(filename);
    Image image2(image.width,image.height);


    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j <image.height; ++j) {
            int flip = image.width-1-i;
            image2(flip,j, 0) =image(i, j, 0) ;
            image2(flip,j, 1) =image(i, j, 1) ;
            image2(flip,j, 2) =image(i, j, 2);
        }
    }

    image2.saveImage(save.toStdString());
    return image2;
}
/*
 * @brief function to implement Rotating  photo 90
 *
 * @param img1 - image we are going to Rotate
 * @return - return an Image Rotated 90
 */

Image rotateImage90( Image& img1) {
    Image img2(img1.height, img1.width);
    for (int i = 0; i < img1.width; ++i) {
        for (int j = 0; j < img1.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                img2(img1.height - 1 - j, i, k) = img1(i, j, k);
            }
        }
    }

    img2.saveImage(save.toStdString());
    return img2;
}
/*
 * @brief function to implement Rotating  photo 180 by using rotateImage90(); twice
 *
 * @param img1 - image we are going to Rotate
 * @return - return an Image Rotated 180
 */
Image rotateImage180( Image& img1) {
    Image img2 = rotateImage90(img1);
    Image img3 = rotateImage90(img2);
    img3.saveImage(save.toStdString());
    return img3;
}
/*
 * @brief function to implement Rotating  photo 270 by using rotateImage90(); three times
 *
 * @param img1 - image we are going to Rotate
 * @return - return an Image Rotated 270
 */
Image rotateImage270( Image& img1) {
    // Rotate the image 90 degrees clockwise
    Image img2 = rotateImage90(img1);
    Image img3 = rotateImage90(img2);
    Image img4 = rotateImage90(img3);
    img4.saveImage(save.toStdString());
    return img4;
}
/*
 * @brief function to implement  effecting a photo by darken or lighten it
 *
 * @param filename - image we are going to load
 * @param choice - image choice whether darken or lighten
 * @param level - image level to decide how darker you want it
 * @return - return an Image effected darken or lighten it
 */
Image darken_or_lighten(string img_name , int choice , double percent)
{
    Image img(img_name) ;
    // Darken
    if(choice == 1){
        for (int i = 0; i < img.width; ++i) {
            for (int j = 0; j < img.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    img(i, j, k) *= ((100 - percent)/100.0);
                }
            }
        }
    }
    // lighten
    else if(choice == 2) {
        for (int i = 0; i < img.width; ++i) {
            for (int j = 0; j < img.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    img(i, j, k) = (img(i, j, k) * (1+percent/100.0)) > 255 ? 255 : img(i, j, k) * (1+percent/100.0);
                }
            }
        }
    }
    img.saveImage(save.toStdString());
    return img ;
}

/*
 * @brief function to implement Croping a photo
 *
 * @param filename - image we are going to load
 * @param width - new image width
 * @param height - new image height
 * @param x - new image x
 * @param y - new image y
 * @return - return an Image Croped
 */
Image Crop(string filename,int width,int height,int x,int y ) {
    Image image(filename);
    // Create a new image to store the selected region
    Image image2(width, height);

    // Copy the selected region from the original image to the new image
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            image2(i, j, 0) = image(x + i, y + j, 0);
            image2(i, j, 1) = image(x + i, y + j, 1);
            image2(i, j, 2) = image(x + i, y + j, 2);
        }
    }


    // Save the new image
    image2.saveImage(save.toStdString());
    return image;
}
/*
 * @brief function to implement Adding a Frame to a Photo
 *
 * @param filename - image we are going to load
 * @param border - Frame border size
 * @param color - Frame color
 * @return - return an Image Croped
 */
Image addNormalFrame(string filename, int border,string color) {
    Image img1(filename);
    for (int i = 0; i < img1.width; ++i) {
        for (int j = 0; j < img1.height; ++j) {
            if ((i < border || i >= img1.width - border) ||
                (j < border || j >= img1.height - border)) {
                if (color == "blue") {
                    img1(i, j, 0) = 0;
                    img1(i, j, 1) = 0;
                    img1(i, j, 2) = 255;
                } else if (color == "red") {
                    img1(i, j, 0) = 255;
                    img1(i, j, 1) = 0;
                    img1(i, j, 2) = 0;
                } else if (color == "green") {
                    img1(i, j, 0) = 0;
                    img1(i, j, 1) = 255;
                    img1(i, j, 2) = 0;

                }
                else if (color=="black"){
                    img1(i, j, 0) = 0;
                    img1(i, j, 1) = 0;
                    img1(i, j, 2) = 0;
                }
            }
        }
    }
    img1.saveImage(save.toStdString());
    return img1;
}
/*
 * @brief function to implement Adding a Frame to a Photo
 *
 * @param filename - image we are going to load
 * @param border - Frame border size
 * @param color - Frame color
 * @param color2 - Frame color2 (Inner frame )
 * @return - return an Image Framed
 */
Image addFancyFrame(string filename, int border,string color , string color2) {
    Image img(filename);
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            if ((i < border || i >= img.width - border) ||
                (j < border || j >= img.height - border)) {
                if (color == "blue") {
                    img(i, j, 0) = 0;
                    img(i, j, 1) = 0;
                    img(i, j, 2) = 255;
                } else if (color == "red") {
                    img(i, j, 0) = 255;
                    img(i, j, 1) = 0;
                    img(i, j, 2) = 0;
                } else if (color == "green") {
                    img(i, j, 0) = 0;
                    img(i, j, 1) = 255;
                    img(i, j, 2) = 0;

                }
                else if (color=="black"){
                    img(i, j, 0) = 0;
                    img(i, j, 1) = 0;
                    img(i, j, 2) = 0;
                }
            }
            if (((i <= border * 2 && i > (border * 3 / 2)) || (i >= img.width - border * 2 && i < img.width - (border * 3 / 2))) ||
                ((j <= border * 2 && j > (border * 3 / 2)) || (j >= img.height - border * 2 && j < img.height - (border * 3 / 2)))) {
                if (color2=="White"){
                    img(i, j, 0) = 255;
                    img(i, j, 1) = 255;
                    img(i, j, 2) = 255;
                }
                else if (color2=="Blue"){
                    img(i, j, 0) = 0;
                    img(i, j, 1) = 0;
                    img(i, j, 2) = 255;
                }else if (color2=="Red"){
                    img(i, j, 0) = 255;
                    img(i, j, 1) = 0;
                    img(i, j, 2) = 0;
                }else if (color2=="Green"){
                    img(i, j, 0) = 0;
                    img(i, j, 1) = 255;
                    img(i, j, 2) = 0;
                }
                else if (color2=="black"){
                    img(i, j, 0) = 0;
                    img(i, j, 1) = 0;
                    img(i, j, 2) = 0;
                }
            }
        }
    }
    img.saveImage(save.toStdString());
    return img;
}

/*
 * @brief function to implement Detecting edges for a photo
 *
 * @param filename - image we are going to load
 * @return - return an Image Detected
 */
Image detect_image_edges(string img_name)
{
    Image image(img_name) ;
    Image img(image.width,image.height) ;
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                img(i,j,k) = 255 ;
            }
        }
    }
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
    for (int i = 1; i < image.width-1; ++i) {
        for (int j = 1; j < image.height-1; ++j) {
            for (int k = 0; k < 3; ++k) {
                if(abs(image(i,j,k) - image(i,j-1,k)) > 20){
                    img(i,j,k) = image(i,j,k) ;
                }
            }
        }
    }

    img.saveImage(save.toStdString());
    return img ;
}
/*
 * @brief function to implement Resizing a photo
 *
 * @param filename - image we are going to load
 * @param width - new image width
 * @param height - new image height
 * @return - return an Image Resized
 */
Image Resize(string filename,int new_width,int new_height) {
    Image image(filename);



    Image resized_image(new_width, new_height);


    for (int i = 0; i < resized_image.width; ++i) {
        for (int j = 0; j < resized_image.height; ++j) {
            int original_x = i * image.width / resized_image.width;
            int original_y = j * image.height / resized_image.height;

            resized_image(i, j, 0) = image(original_x, original_y, 0);
            resized_image(i, j, 1) = image(original_x, original_y, 1);
            resized_image(i, j, 2) = image(original_x, original_y, 2);
        }
    }
    resized_image.saveImage(save.toStdString());
    return resized_image;
}
/*
 * @brief function to implement Bluring a photo
 *
 * @param filename - image we are going to load
 * @param radius - Blur radius
 * @return - return an Image Blured
 */
Image Blur( string filename, int radius) {
    Image img(filename);
    int width = img.width;
    int height = img.height;
    for (int i = radius / 2; i < width - radius / 2; ++i) {
        for (int j = radius / 2; j < height - radius / 2; ++j) {
            int red = 0, green = 0, blue = 0;
            int count = 0;
            for (int l = -radius / 2; l <= radius / 2; ++l) {
                for (int x = -radius / 2; x <= radius / 2; ++x) {
                    if (i + l >= 0 && i + l < width && j + x >= 0 && j + x < height) {
                        red += img(i + l, j + x, 0);
                        green += img(i + l, j + x, 1);
                        blue += img(i + l, j + x, 2);
                        count++;
                    }
                }
            }
            if (count > 0) {
                red /= count;
                green /= count;
                blue /= count;
            }
            img(i, j, 0)=red;
            img(i, j, 1)=green;
            img(i, j, 2)=blue;

        }
    }
    img.saveImage(save.toStdString());
    return img;
}

// /////////////////////////////**********************bonus**********************\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

/*
 * @brief function to implement  effecting a photo by sun
 *
 * @param filename - image we are going to load
 * @return - return an Image effected by sun
 */
Image Filter_13( string filename) {
    Image img1(filename);
    for (int i = 0; i < img1.width; ++i) {
        for (int j = 0; j < img1.height; ++j) {
            int red = img1(i, j, 0) + 60;
            int green = img1(i, j, 1) + 30;
            int blue = img1(i, j, 2);
            if (red > 255) red = 255;
            if (green > 255) green = 255;
            if (blue > 255) blue = 255;
            img1(i, j, 0) = red;
            img1(i, j, 1) = green;
            img1(i, j, 2) = blue;
        }
    }
    img1.saveImage(save.toStdString());
    return img1;
}
/*
 * @brief function to implement  effecting a photo by drawing it with oil
 *
 * @param filename - image we are going to oilpainting it
 * @param radius - image radius
 * @param Level - image Level for photo intinsity
 * @return - return an Image effected by drawing it with oil
 */
Image OilPaintingEffect( string filename, int radius, int Level) {
    Image img(filename);
    int width = img.width;
    int height = img.height;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            vector<int> Count(Level, 0);
            vector<int> sumR(Level, 0);
            vector<int> sumG(Level, 0);
            vector<int> sumB(Level, 0);
            for (int j = max(0, y - radius); j <= min(height - 1, y + radius); ++j) {
                for (int i = max(0, x - radius); i <= min(width - 1, x + radius); ++i) {
                    int z = static_cast<int>((img(i, j, 0) + img(i, j, 1) +
                                              img(i, j, 2)) / 3.0 * Level / 255.0);
                    Count[z]++;
                    sumR[z] += img(i, j, 0);
                    sumG[z] += img(i, j, 1);
                    sumB[z] += img(i, j, 2);
                }
            }
            int maxCount = 0;
            int maxIndex = 0;
            for (int k = 0; k < Level; ++k) {
                if (Count[k] > maxCount) {
                    maxCount = Count[k];
                    maxIndex = k;
                }
            }
            img(x, y, 0) = sumR[maxIndex] / maxCount;
            img(x, y, 1) = sumG[maxIndex] / maxCount;
            img(x, y, 2) = sumB[maxIndex] / maxCount;
        }
    }
    img.saveImage(save.toStdString());
    return img;
}

/*
 * @brief function to implement  effecting a  noise
 *
 * @param filename - image we are going to load it
 * @return - return an Image effected by a noise
 */
Image old_tv_filter(string img_name)
{
    Image img1(img_name) ;
    Image img2(img_name) ;
    for (int i = 0; i < img1.width; ++i) {
        for (int j = 0; j < img1.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int x = rand()%255 ;
                if(i % 2 == 0 )
                    img1(i,j,k) -= x ;
                else
                    img1(i,j,k) += x ;
            }
        }
    }
    for (int i = 0; i < img2.width; ++i) {
        for (int j = 0; j < img2.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                img2(i,j,k) -= img2(i,j,k)/3 ;
                img2(i,j,k) += img1(i,j,k)/3 ;
            }
        }
    }
    img2.saveImage(save.toStdString());
    return img2 ;
}
/*
 * @brief function to implement converting a photo to purple
 *
 * @param filename - image we are going to oilpainting it
 * @return - return an Image converted to purple
 */
Image  purple(string filename ) {
    Image image(filename);
    Image purple_image(image.width, image.height);


    for (int i = 0; i < purple_image.width; ++i) {
        for (int j = 0; j < purple_image.height; ++j) {

            purple_image(i, j, 0) = min(255,image(i, j, 0)*7/9);
            purple_image(i, j, 1) = image(i, j, 1)*2/5 ;
            purple_image(i, j, 2) = min(255,image(i, j, 2)*7/9);
        }
    }

    purple_image.saveImage(save.toStdString());


    return purple_image;
}


/*
 * @brief function to implement converting a photo to inferared
 *
 * @param filename - image we are going to load it
 * @return - return an Image converted to Inferared
 */
Image  inferared(string filename ) {
    Image image(filename);
    Image inferared_image(image.width, image.height);


    for (int i = 0; i < inferared_image.width; ++i) {
        for (int j = 0; j < inferared_image.height; ++j) {

            inferared_image(i, j, 0) = 220;
            inferared_image(i, j, 1) =255- image(i, j, 1) ;
            inferared_image(i, j, 2) =255-image(i, j, 2);
        }
    }

    inferared_image.saveImage(save.toStdString());


    return inferared_image;
}
/*
 * @brief function to implement Skewing a photo
 *
 * @param filename - image we are going to load it
 * @param angel - angel to skew photo based on it
 * @return - return an Image Skewed
 */

Image skewing_filter(string img_name , int angel)
{
    Image img1(img_name) ;
    double h = img1.height , w = img1.width , x = (h * cos((angel/180.0)*3.1416)) , l = h * sin((angel/180.0)*3.1416);
    double slope = tan((angel/180.0)*3.1416);
    Image img2(img1.width + x , l);
    int z = 0 ;
    for (double i = 0; i < img2.height; i += l/h) {
        int m = 0 ;
        for (double j = x - i/slope; j < img2.width-(i/slope); j += 1.0) {
            for (int k = 0; k < 3; ++k) {
                img2(j,i,k) = img1(m,z,k);
            }
            m++;
        }
        z++ ;
    }
    img2.saveImage(save.toStdString());
    return img2 ;
}
/*
 * @brief function to implement Convert a photo to Demon
 *
 * @param filename - image we are going to load it
 * @return - return an Image Converted to Demon
 */

Image  Demon(string filename ) {
    Image image(filename);
    Image Demon_image(image.width, image.height);


    for (int i = 0; i < Demon_image.width; ++i) {
        for (int j = 0; j < Demon_image.height; ++j) {

            Demon_image(i, j, 0) = 255-image(i, j, 2);
            Demon_image(i, j, 1) = image(i, j, 1)/3;
            Demon_image(i, j, 2) = image(i, j, 0)/5;
        }
    }

    Demon_image.saveImage(save.toStdString());


    return Demon_image;
}

/*
 * @brief function to implement Converting  a photo to Zompie
 *
 * @param filename - image we are going to load it
 * @return - return an Image Converted to Zompie
 */

Image rand(string filename) {
    Image image(filename);
    Image rand_image(image.width, image.height);


    for (int i = 0; i < rand_image.width; ++i) {
        for (int j = 0; j < rand_image.height; ++j) {

            // Assign random values to each channel of the rand_image
            rand_image(i, j, 0) = image(i,j,2)/9;
            rand_image(i, j, 1) = image(i,j,2)*7/5;
            rand_image(i, j, 2) = image(i,j,0)/2;
        }
    }

    rand_image.saveImage(save.toStdString());

    return rand_image;
}

#endif // FILTERS_H
