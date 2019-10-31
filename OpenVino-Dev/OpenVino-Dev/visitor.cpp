#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"

#include <QDebug>
#include <functional>
#include <iostream>
#include <fstream>
#include <random>
#include <memory>
#include <chrono>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iterator>
#include <map>
#include <list>
#include <set>

#include <inference_engine.hpp>

#include <samples/ocv_common.hpp>
#include <samples/slog.hpp>

#include "interactive_face_detection.hpp"


#include "cnn.hpp"
#include "face_reid.hpp"
#include "visitor.h"
#include "database.hpp"

using namespace std;
using namespace cv;
using namespace InferenceEngine;

#if 0
Timer timer;
int firstTime = 0;
bool firstPhoto = true;
cv::Mat face_save;
bool face_identified = false;


bool identify_driver(cv::Mat frame, std::vector<FaceDetection::Result> *results, VectorCNN *landmarks_detector,
                     VectorCNN *face_reid, EmbeddingsGallery *face_gallery, std::string *driver_name)
{
    bool ret = false;
    std::vector<cv::Mat> face_rois, landmarks, embeddings;

    if (results->empty())
        return ret;

    for (const auto &face : *results)
    {
        cv::Rect rect = face.location;
        float scale_factor_x = 0.15;
        float scale_factor_y = 0.20;
        double aux_x = (rect.x > 3 ? rect.x : 3);
        double aux_y = (rect.y > 3 ? rect.y : 3);
        double aux_width = (rect.width + aux_x < frame.cols ? rect.width : frame.cols - aux_x);
        double aux_height = (rect.height + aux_y < frame.rows ? rect.height : frame.rows - aux_y);
        aux_x += scale_factor_x * aux_width;
        aux_y += scale_factor_y * aux_height;
        aux_width = aux_width * (1 - 2 * scale_factor_x);
        aux_height = aux_height * (1 - scale_factor_y);
        cv::Rect aux_rect = cv::Rect(aux_x, aux_y, aux_width, aux_height);
        face_rois.push_back(frame(aux_rect));
    }

    if (!face_rois.empty())
    {
        landmarks_detector->Compute(face_rois, &landmarks, cv::Size(2, 5));
        AlignFaces(&face_rois, &landmarks);
        face_reid->Compute(face_rois, &embeddings);
        auto ids = face_gallery->GetIDsByEmbeddings(embeddings);

        for (size_t i = 0; i < results->size(); i++) {
            if (!ids.empty() && ids[i] != EmbeddingsGallery::unknown_id)
            {
                ret = true;
                *driver_name = face_gallery->GetLabelByID(ids[i]);
                std::cout<<*driver_name<<"  ";
            }
            else
                *driver_name = "Unknown";
        }
        std::cout <<std::endl;
/*
        if (!ids.empty() && ids[0] != EmbeddingsGallery::unknown_id)
        {
            ret = true;
            *driver_name = face_gallery->GetLabelByID(ids[0]);
            std::cout<<*driver_name<<std::endl;
        }
        else
            *driver_name = "Unknown";*/

    }

    return ret;
}

// Thread 1: Driver Recognition
void driver_recognition(cv::Mat prev_frame, std::vector<FaceDetection::Result> prev_detection_results, VectorCNN landmarks_detector, VectorCNN face_reid, EmbeddingsGallery face_gallery, std::string *driver_name, int x_truck_i, int y_driver_i)
{
    if (timer["face_identified"].getSmoothedDuration() > 3000.0 && face_identified && firstTime == 1 ||
        timer["face_identified"].getSmoothedDuration() > 500.0 && !face_identified && firstTime == 1 ||
        firstTime == 0)
    {
        cv::Mat aux_prev_frame = prev_frame.clone();
        face_identified = identify_driver(aux_prev_frame, &prev_detection_results, &landmarks_detector, &face_reid, &face_gallery, driver_name);
        //if (!prev_detection_results.empty())
        //    cv::rectangle(prev_frame, prev_detection_results[0].location, cv::Scalar(255, 255, 255), 1);
        firstTime = 1;
        timer.start("face_identified");
        //Take Photo
        if (!face_identified && firstPhoto) // Only save the first picture of the "Not Authorized Driver".
        {
            cv::imwrite("Unknown-Driver.jpg", face_save);
            firstPhoto = false;
        }
    }
/*
    if(face_identified)
        cv::putText(prev_frame, *driver_name, cv::Point2f(prev_detection_results[0].location.x, prev_detection_results[0].location.y + 20), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255), 1);*/
}
#endif

/*
void UpdateTotalTable_TimeOut(void)
{
    int malenum = QueryTotalPerson(PERSONTABLE , "male");
    int femalenum = QueryTotalPerson(PERSONTABLE , "female");

    updatechart(malenum , femalenum);
}*/

VisitorThread::VisitorThread()
{
    VisitorRunning = true;
}

void VisitorThread::run()
{


    qDebug()<<"Visitor Thread Running !!";
    VisitorRunning = true;

    Timer timer;

    //cap.open(FLAGS_i);
    cap.open(0);
    //cap.open("/opt/sample-video/face-demographics-walking.mp4");
    if(!cap.isOpened())
    {
            printf("open video file failed\n");
            return;
    }
    else
            printf("open video ok\n");

    //cap.set(cv::CAP_PROP_FRAME_HEIGHT, 720);
    //cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);

    cv::Mat frame;
    if (!cap.read(frame)) {
        throw std::logic_error("Failed to get frame from cv::VideoCapture");
    }

    const size_t width  = static_cast<size_t>(frame.cols);
    const size_t height = static_cast<size_t>(frame.rows);

    std::cout << "Get Video Width/Height!!!!!!!!" << std::endl;
    std::cout << width << std::endl;
    std::cout << height << std::endl;

    Core ie;
    std::set<std::string> loadedDevices;
    std::map<std::string, Core> pluginsForDevices;
    std::vector<std::pair<std::string, std::string>> cmdOptions =
    {
        {FLAGS_d, FLAGS_m},
        {FLAGS_d_ag, FLAGS_m_ag},
        {FLAGS_d_hp, FLAGS_m_hp},
        {FLAGS_d_em, FLAGS_m_em},
        {FLAGS_d_lm, FLAGS_m_lm}
    };

    std::cout << FLAGS_m << std::endl;
    std::cout << FLAGS_d << std::endl;
    std::cout << FLAGS_m_ag << std::endl;
    std::cout << FLAGS_m_hp << std::endl;
    std::cout << FLAGS_m_em << std::endl;
    std::cout << FLAGS_m_lm << std::endl;

    FaceDetection faceDetector(FLAGS_m, FLAGS_d, 1, false, FLAGS_async, FLAGS_t, FLAGS_r,
                                       static_cast<float>(FLAGS_bb_enlarge_coef), static_cast<float>(FLAGS_dx_coef), static_cast<float>(FLAGS_dy_coef));
    AgeGenderDetection ageGenderDetector(FLAGS_m_ag, FLAGS_d_ag, FLAGS_n_ag, FLAGS_dyn_ag, FLAGS_async, FLAGS_r);
    HeadPoseDetection headPoseDetector(FLAGS_m_hp, FLAGS_d_hp, FLAGS_n_hp, FLAGS_dyn_hp, FLAGS_async, FLAGS_r);
    EmotionsDetection emotionsDetector(FLAGS_m_em, FLAGS_d_em, FLAGS_n_em, FLAGS_dyn_em, FLAGS_async, FLAGS_r);
    FacialLandmarksDetection facialLandmarksDetector(FLAGS_m_lm, FLAGS_d_lm, FLAGS_n_lm, FLAGS_dyn_lm, FLAGS_async, FLAGS_r);


    auto fr_model_path = FLAGS_m_reid;
    auto fr_weights_path = fileNameNoExt(FLAGS_m_reid) + ".bin";
    auto lm_model_path = FLAGS_m_lm;
    auto lm_weights_path = fileNameNoExt(FLAGS_m_lm) + ".bin";

    int max_batch_size = 1;



    //const size_t width_frame = (size_t)cap.get(cv::CAP_PROP_FRAME_WIDTH);
    //const size_t height_frame = (size_t)cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    //int x = 200;
    //int y = 155;
    //int x_truck_i = width_frame - (x + 10);
    //int y_driver_i = y + 30;

    std::string driver_name = "";
    //std::map<std::string, Core> pluginsForDevices;

    CnnConfig reid_config(fr_model_path, fr_weights_path);
    reid_config.max_batch_size = max_batch_size;
    reid_config.enabled = /*face_config.enabled*/ true && !fr_model_path.empty() && !lm_model_path.empty();
    reid_config.plugin = pluginsForDevices[FLAGS_d_reid];
    reid_config.deviceName = FLAGS_d_reid;
    VectorCNN face_reid(reid_config);

    // Load landmarks detector
    CnnConfig landmarks_config(lm_model_path, lm_weights_path);
    landmarks_config.max_batch_size = max_batch_size;
    landmarks_config.enabled = /*face_config.enabled*/ true && reid_config.enabled && !lm_model_path.empty();
    landmarks_config.plugin = pluginsForDevices[FLAGS_d_lm];
    landmarks_config.deviceName = FLAGS_d_lm;
    VectorCNN landmarks_detector(landmarks_config);
/*
    std::cout << "FLAGS_m_reid:" << FLAGS_m_reid << std::endl;
    std::cout << "FLAGS_m_lm:" << FLAGS_m_lm << std::endl;
    std::cout << "FLAGS_d_reid:" << FLAGS_d_reid << std::endl;
    std::cout << "FLAGS_fg:" << FLAGS_fg << std::endl;*/

    double t_reid = 0.4; // Cosine distance threshold between two vectors for face reidentification.
    EmbeddingsGallery face_gallery(FLAGS_fg, t_reid, landmarks_detector, face_reid);

    for (auto && option : cmdOptions)
    {
        auto deviceName = option.first;
        auto networkName = option.second;

        if (deviceName.empty() || networkName.empty()) {
            continue;
        }

        if (loadedDevices.find(deviceName) != loadedDevices.end()) {
            continue;
        }
        slog::info << "Loading device " << deviceName << slog::endl;
        std::cout << ie.GetVersions(deviceName) << std::endl;

        // Loading extensions for the CPU device
        if ((deviceName.find("CPU") != std::string::npos)) {
            ie.AddExtension(std::make_shared<Extensions::Cpu::CpuExtensions>(), "CPU");

            if (!FLAGS_l.empty()) {
                // CPU(MKLDNN) extensions are loaded as a shared library and passed as a pointer to base extension
                auto extension_ptr = make_so_pointer<IExtension>(FLAGS_l);
                ie.AddExtension(extension_ptr, "CPU");
                slog::info << "CPU Extension loaded: " << FLAGS_l << slog::endl;
            }
        } else if (!FLAGS_c.empty()) {
            // Loading extensions for GPU
            ie.SetConfig({{PluginConfigParams::KEY_CONFIG_FILE, FLAGS_c}}, "GPU");
        }

        loadedDevices.insert(deviceName);
    }

    // --------------------------- 2. Reading IR models and loading them to plugins ----------------------
    //Disable dynamic batching for face detector as it processes one image at a time
    Load(faceDetector).into(ie, FLAGS_d, false);
    Load(ageGenderDetector).into(ie, FLAGS_d_ag, FLAGS_dyn_ag);
    Load(headPoseDetector).into(ie, FLAGS_d_hp, FLAGS_dyn_hp);
    Load(emotionsDetector).into(ie, FLAGS_d_em, FLAGS_dyn_em);
    //Load(facialLandmarksDetector).into(ie, FLAGS_d_lm, FLAGS_dyn_lm);
    // ----------------------------------------------------------------------------------------------------

    // --------------------------- 3. Doing inference -----------------------------------------------------
    // Starting inference & calculating performance
    std::cout << "Start inference " << std::endl;

    bool isFaceAnalyticsEnabled = ageGenderDetector.enabled() || headPoseDetector.enabled() ||
                                  emotionsDetector.enabled() || facialLandmarksDetector.enabled();

    std::ostringstream out;
    size_t framesCounter = 0;
    bool frameReadStatus;
    bool isLastFrame;
    int delay = 1;
    double msrate = -1;
    cv::Mat prev_frame, next_frame;
    std::list<Face::Ptr> faces;
    size_t id = 0;

    if (FLAGS_fps > 0) {
        msrate = 1000.f / FLAGS_fps;
    }
    Visualizer::Ptr visualizer;
    if (!FLAGS_no_show || !FLAGS_o.empty()) {
        visualizer = std::make_shared<Visualizer>(cv::Size(width, height));
        if (!FLAGS_no_show_emotion_bar && emotionsDetector.enabled()) {
            visualizer->enableEmotionBar(emotionsDetector.emotionsVec);
        }
    }

    // Detecting all faces on the first frame and reading the next one
    faceDetector.enqueue(frame);
    faceDetector.submitRequest();

    prev_frame = frame.clone();

    // Reading the next frame
    frameReadStatus = cap.read(frame);
/*
    slog::info << "To close the application, press 'CTRL+C' here";
    if (!FLAGS_no_show) {
        slog::info << " or switch to the output window and press any key";
    }
    slog::info << slog::endl;
    slog::info << "start !!!!!!!!!!!!!!!!!\n" << slog::endl;
*/
    //创建数据库
   if (FAIL == CreateDatabaseConnectionSwitch(db , ON))
    {
           slog::info<<("链接数据库失败")<<slog::endl;
    }

   if (FAIL == CreatePersonAttributeTab(PERSONTABLE))
    {
        slog::info<<("数据库表创建失败")<<slog::endl;
    }

    //QueryVistorsNum(PERSONTABLE)

    slog::info << "-----------------------------------------"<<slog::endl;
    QueryWholeTable(PERSONTABLE);
    slog::info << "-----------------------------------------"<<slog::endl;

    /* 根据数据库中的男女比例，更新图表 */
    int malenum = QueryTotalPerson(PERSONTABLE , "male");
    int femalenum = QueryTotalPerson(PERSONTABLE , "female");

    updatechart(malenum , femalenum);

    slog::info<<"男："<<malenum<<slog::endl;
    slog::info<<"女："<<femalenum<<slog::endl;

    int TotalRecord = malenum + femalenum;
    struct personAttribute *pAttTotal = new struct personAttribute[TotalRecord+1];
    qryCondstr qryCond;
    qryCond.startAddr = 0;
    qryCond.dataLenth =TotalRecord;
    QueryVistorsNum(pAttTotal ,PERSONTABLE , &qryCond);
    inittable(TotalRecord , pAttTotal);

    //Timer timer;
    timer.start("face_identified");
    while (VisitorRunning) {
        timer.start("total");
        framesCounter++;
        isLastFrame = !frameReadStatus;

        // Retrieving face detection results for the previous frame
        faceDetector.wait();
        faceDetector.fetchResults();
        //std::cout << height << std::endl;

        auto prev_detection_results = faceDetector.results;

        // No valid frame to infer if previous frame is the last
        if (!isLastFrame) {
            faceDetector.enqueue(frame);
            faceDetector.submitRequest();
        }

        // Filling inputs of face analytics networks
        for (auto &&face : prev_detection_results) {
            if (isFaceAnalyticsEnabled) {
                auto clippedRect = face.location & cv::Rect(0, 0, width, height);
                cv::Mat face = prev_frame(clippedRect);
                ageGenderDetector.enqueue(face);
                headPoseDetector.enqueue(face);
                emotionsDetector.enqueue(face);
                //facialLandmarksDetector.enqueue(face);
            }
        }

        // Running Age/Gender Recognition, Head Pose Estimation, Emotions Recognition, and Facial Landmarks Estimation networks simultaneously
        if (isFaceAnalyticsEnabled) {
            ageGenderDetector.submitRequest();
            headPoseDetector.submitRequest();
            emotionsDetector.submitRequest();
            //facialLandmarksDetector.submitRequest();
        }

        // Reading the next frame if the current one is not the last
        if (!isLastFrame) {
            frameReadStatus = cap.read(next_frame);
            if (FLAGS_loop_video && !frameReadStatus) {
                if (!(FLAGS_i == "cam" ? cap.open(0) : cap.open(FLAGS_i))) {
                    throw std::logic_error("Cannot open input file or camera: " + FLAGS_i);
                }
                frameReadStatus = cap.read(next_frame);
            }
        }

        if (isFaceAnalyticsEnabled) {
                        ageGenderDetector.wait();
                        headPoseDetector.wait();
                        emotionsDetector.wait();
                        //facialLandmarksDetector.wait();
        }

        //  Postprocessing
        std::list<Face::Ptr> prev_faces;

        if (!FLAGS_no_smooth) {
            prev_faces.insert(prev_faces.begin(), faces.begin(), faces.end());
        }

        faces.clear();

        // For every detected face
        //model->setColumnCount(prev_detection_results.size());//修改QTableView的为实际数量
        sendTotalFace(prev_detection_results.size());

        std::vector<cv::Mat> face_rois, landmarks, embeddings;

        for (size_t i = 0; i < prev_detection_results.size(); i++) {
            auto& result = prev_detection_results[i];
            cv::Rect rect = result.location & cv::Rect(0, 0, width, height);

            Face::Ptr face;
            if (!FLAGS_no_smooth) {
                face = matchFace(rect, prev_faces);
                float intensity_mean = calcMean(prev_frame(rect));

                if ((face == nullptr) ||
                    ((face != nullptr) && ((std::abs(intensity_mean - face->_intensity_mean) / face->_intensity_mean) > 0.07f))) {
                    face = std::make_shared<Face>(id++, rect);
                } else {
                    prev_faces.remove(face);
                }

                face->_intensity_mean = intensity_mean;
                face->_location = rect;
            } else {
                face = std::make_shared<Face>(id++, rect);
            }

            face->ageGenderEnable((ageGenderDetector.enabled() &&
                                   i < ageGenderDetector.maxBatch));
            if (face->isAgeGenderEnabled()) {
                AgeGenderDetection::Result ageGenderResult = ageGenderDetector[i];
                face->updateGender(ageGenderResult.maleProb);
                face->updateAge(ageGenderResult.age);
            }


            face->emotionsEnable((emotionsDetector.enabled() &&
                                  i < emotionsDetector.maxBatch));
            if (face->isEmotionsEnabled()) {
                face->updateEmotions(emotionsDetector[i]);
            }
            face->headPoseEnable((headPoseDetector.enabled() &&
                                  i < headPoseDetector.maxBatch));
            if (face->isHeadPoseEnabled()) {
                face->updateHeadPose(headPoseDetector[i]);
            }
/*
            face->landmarksEnable((facialLandmarksDetector.enabled() &&
                                   i < facialLandmarksDetector.maxBatch));
            if (face->isLandmarksEnabled()) {
                face->updateLandmarks(facialLandmarksDetector[i]);
            }*/

            sendFaceInfo(face , i);



            /* 进行人脸再识别，分辨出人物名字，将人物名字和其他信息一起写入链表 */
            cv::Mat aux_prev_frame = prev_frame.clone();
            face_rois.push_back(aux_prev_frame(face->_location));

            landmarks_detector.Compute(face_rois, &landmarks, cv::Size(2, 5));
            AlignFaces(&face_rois, &landmarks);
            face_reid.Compute(face_rois, &embeddings);
            auto ids = face_gallery.GetIDsByEmbeddings(embeddings);
            if (!ids.empty() && ids[i] != EmbeddingsGallery::unknown_id)
            {
                face->updatefacename(face_gallery.GetLabelByID(ids[i]));
            }
            else {
                face->updatefacename("Unknown");
            }

            // 添加显示---年龄、性别、表情状态
            /*model->setItem(0, i, new QStandardItem(QString::number(face->getId() , 10)));
            model->setItem(1, i, new QStandardItem(face->isMale()?"男":"女"));
            model->setItem(2, i, new QStandardItem(QString::number(face->getAge() , 10)));

            auto emotion = face->getMainEmotion();
            model->setItem(3, i, new QStandardItem(emotion.first.data()));*/
            //std::cout<<emotion.first.data()<<std::endl;

            /*将识别到的信息添加到数据库中 */
            struct personAttribute QtPerAttrTable;
            QtPerAttrTable.id = face->getId();
            //QtPerAttrTable.name ="liuyg";
            QtPerAttrTable.sex = face->isMale()?"男":"女";
            QtPerAttrTable.age = face->getAge();
            QtPerAttrTable.expression =face->getMainEmotion().first.data();
            QtPerAttrTable.name =face->getfacename();

            QDateTime current_time = QDateTime::currentDateTime();
            QString StrCurrentTime = current_time.toString("yyyy.MM.dd hh:mm:ss");
            QtPerAttrTable.time = StrCurrentTime.toStdString();

            if(SUCC == AddOnePersonAttribute(&QtPerAttrTable , PERSONTABLE))
            {
                /* 插入到数据库成功，更新图表 */
                int malenum = QueryTotalPerson(PERSONTABLE , "male");
                int femalenum = QueryTotalPerson(PERSONTABLE , "female");

                updatechart(malenum , femalenum);

                updatetable(&QtPerAttrTable);
            }


            faces.push_back(face);
        }

        //std::vector<cv::Mat> face_rois, landmarks, embeddings;
        /*for (const auto& face : faces) {
            face_rois.push_back(prev_frame(face->_location));
        }

        landmarks_detector.Compute(face_rois, &landmarks, cv::Size(2, 5));
        AlignFaces(&face_rois, &landmarks);
        face_reid.Compute(face_rois, &embeddings);
        auto ids = face_gallery.GetIDsByEmbeddings(embeddings);

        for (size_t i = 0; i < faces.size(); i++) {

            if (!ids.empty() && ids[i] != EmbeddingsGallery::unknown_id)
                std::cout << "1"<<face_gallery.GetLabelByID(ids[i]);
        }
        std::cout<<std::endl;*/


       //std::thread thread_recognition(driver_recognition, prev_frame, prev_detection_results, landmarks_detector, face_reid, face_gallery, &driver_name, x_truck_i, y_driver_i);

        //slog::info << driver_name << slog::endl;
        //  Visualizing results
        if (!FLAGS_no_show || !FLAGS_o.empty()) {
            // drawing faces
            visualizer->draw(prev_frame, faces);
        }
        //cv::imshow("Detection results", prev_frame);

        QImage image = QImage(prev_frame.data,prev_frame.cols,prev_frame.rows,QImage::Format_RGB888).rgbSwapped();
        //ui->label_video->setPixmap(QPixmap::fromImage(image));
        //sendimage(image);
        sendImage(image);

        prev_frame = frame;
        frame = next_frame;
        next_frame = cv::Mat();

        timer.finish("total");

        if (FLAGS_fps > 0) {
            delay = std::max(1, static_cast<int>(msrate - timer["total"].getLastCallDuration()));
        }

        // End of file (or a single frame file like an image). The last frame is displayed to let you check what is shown
        if (isLastFrame) {
            if (!FLAGS_no_wait) {
                std::cout << "No more frames to process!" << std::endl;
                cv::waitKey(0);
            }
            break;
        }

       // thread_recognition.join();
    }
    // Showing performance results
    if (FLAGS_pc) {
        faceDetector.printPerformanceCounts(getFullDeviceName(pluginsForDevices[FLAGS_d], FLAGS_d));
        ageGenderDetector.printPerformanceCounts(getFullDeviceName(pluginsForDevices[FLAGS_d], FLAGS_d_ag));
        headPoseDetector.printPerformanceCounts(getFullDeviceName(pluginsForDevices[FLAGS_d], FLAGS_d_hp));
        emotionsDetector.printPerformanceCounts(getFullDeviceName(pluginsForDevices[FLAGS_d], FLAGS_d_em));
        facialLandmarksDetector.printPerformanceCounts(getFullDeviceName(pluginsForDevices[FLAGS_d], FLAGS_d_lm));
    }

    // release input video stream
    cap.release();

    /* 发送一张默认显示图片,将视频窗口恢复到默认*/
   //QImage image = QImage(":/bt_ico/image/UI_main_1_1.png");
   // sendImage(image);

    qDebug()<<"Pthread exit!!";
}

void VisitorThread::stop()
{
    VisitorRunning = false;   //线程退出标志
    qDebug() << "Visitor Thread end";
}

