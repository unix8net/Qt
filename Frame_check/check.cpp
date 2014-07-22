void MainWindow::run()
{
    bool bstart = false;
    int cnt = 0;
    char tmp[FRAME_LENGTH - 1];
    char buff[2];
    int len;
    long oldTime = -1;
    float data ;
    while(true)
    {
        mutex.lock();
        while(circularQueue.size() <= 2)
        {
           bufferIsEmpty.wait(&mutex);
           if(exitFlag)
           {
               mutex.unlock();
               return;
           }
        }
        if(!bstart)
        {
            while(true)
            {
                if(circularQueue.size() < 2) continue;
                circularQueue.get_n_front(buff, 2);
                if(!(buff[0] ^ HEAD_FIRST) && !(buff[1] ^ HEAD_SECOND))
                {
                    bstart = true;
                    cnt = 0;
                    circularQueue.remove_n_front(2);
                    len = circularQueue.front();
                    break;
                }
                else
                {
                    circularQueue.remove_n_front(1);
                }
            }
        }
        else
        {
            while(true)
            {
                if(circularQueue.size() < 2) break;
                circularQueue.get_n_front(buff,2);
                if(!(buff[0] ^ TAIL_FIRST) && !(buff[1] ^ TAIL_SECOND))
                {
                    memcpy(&data, tmp + 3, sizeof(float));
                    long nowTime = timeBus.getTimeBusCnt();
                    QDateTime time = QDateTime::currentDateTime();

                    if((oldTime > nowTime)
                            ||(oldTime == -1))
                    {
                        QString str = time.toString("yyyyMMdd");
                        rainTable = str + "rn";
                        shallowTable = str + "sh";
                        deepTable = str + "dp";
                        angleTable = str + "ag";
                        stressTable = str + "ss";
                        sqlthread.asyncCreatTable(rainTable);//rain
                        sqlthread.asyncCreatTable(shallowTable);//shallow
                        sqlthread.asyncCreatTable(deepTable);//deep
                        sqlthread.asyncCreatTable(angleTable);//angle
                        sqlthread.asyncCreatTable(stressTable);//stress
                    }
                    oldTime = nowTime;
                    QString strAll = time.toString("yyyy-MM-dd hh:mm:ss");
                    switch ( *(tmp + 1) )
                    {
                    /*!
                      * 以下为将数据分发到各个波形显示模块，而且使用异步方式插入到数据库中
                      */

                    case SpecialBaseWidget::RainfallWidgetId:{
                        emit sendDataToRain(nowTime, data);                 
                        sqlthread.asyncInsertData(rainTable ,strAll, nowTime, data );
                        break;}
                    case SpecialBaseWidget::SuperficialCracksWigget:{
                        emit sendDataToShallow(nowTime, data);                     
                        sqlthread.asyncInsertData(shallowTable ,strAll, nowTime, data );
                        break;}
                    case SpecialBaseWidget::DeepCracksWigget:{
                        emit sendDataToDeep(nowTime, data);
                        sqlthread.asyncInsertData(deepTable ,strAll, nowTime, data );
                        break;}

                    case SpecialBaseWidget::SoilAngleWigget:{
                        emit sendDataToAngle(nowTime, data);
                        sqlthread.asyncInsertData(angleTable ,strAll, nowTime, data );
                        break;}
                    case SpecialBaseWidget::StreeWigget:{
                        emit sendDataToStress(nowTime, data);
                        sqlthread.asyncInsertData(stressTable ,strAll, nowTime, data );
                        break;}
                        default:break;
                    }
                    //qDebug()<<"收到完整的数据帧:"<<cnt;
                    bstart = false;
                    cnt = 0;
                    circularQueue.remove_n_front(2);
                    break;
                }
                else
                {
                    circularQueue.remove_n_front(1);
                    tmp[cnt++] = buff[0];
                    if(cnt >= FRAME_LENGTH -1)
                    {
                        bstart = false;
                        cnt = 0;
                    }
                }

            }
        }
        mutex.unlock();

    }
}