
        int timing = 0;
        double anotherTime = 0;
        double waitingTime = 0;
        double turnAroundTime = 0;

        timing = timing + tempModelList.get(0).getBrustTime();
        anotherTime = timing - tempModelList.get(0).getBrustTime();
        anotherTime = anotherTime - tempModelList.get(0).getArrivalTime();
        waitingTime += anotherTime;
        turnAroundTime += anotherTime + tempModelList.get(0).getBrustTime();
        tempModelList.get(0).setDone(true);
        boolean done = true;

        while(true){
            done = true;
            List<NonPreemtive> anotherList = new ArrayList<>();


            for(int i=0; i<tempModelList.size(); i++){
                if(tempModelList.get(i).getArrivalTime() <= timing && tempModelList.get(i).isDone() == false){
                    anotherList.add(tempModelList.get(i).copy(tempModelList.get(i)));
                    done = false;
                }
            }

            int min = 1000;
            NonPreemtive nonPreemtive = null;

            for(int i=0; i<anotherList.size(); i++){
                if(anotherList.get(i).getBrustTime() < min){
                    min = anotherList.get(i).getBrustTime();
                    nonPreemtive = anotherList.get(i);
                }
            }

            if(nonPreemtive != null){
                timing = timing + nonPreemtive.getBrustTime();
                anotherTime = timing - nonPreemtive.getBrustTime();
                anotherTime = anotherTime - nonPreemtive.getArrivalTime();
                waitingTime += anotherTime;
                turnAroundTime += anotherTime + nonPreemtive.getBrustTime();

                for(int i=0; i<tempModelList.size(); i++){
                    if(tempModelList.get(i).getProcessName() == nonPreemtive.getProcessName()){
                        tempModelList.get(i).setDone(true);
                        break;
                    }

                }
            }


            if (done)
                break;
        }
        System.out.println(waitingTime/models.size());
        System.out.println(turnAroundTime/models.size());


